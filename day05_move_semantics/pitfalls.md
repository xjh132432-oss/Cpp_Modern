# Day05 — Move Semantics Pitfalls

## 1. `std::move` 不会直接移动数据

`std::move` 定义在 `<utility>` 中，本质上是一个类型转换工具，使表达式能够参与右值引用相关重载的匹配。

```cpp
auto student2 = std::move(student1);
```

这行代码本身不保证发生数据移动。实际调用哪个操作，取决于类型、可用的构造函数及重载规则。

**避免误解：** `std::move` 不是负责搬运数据的函数，而是让移动操作有机会被选择。

## 2. 有名字的右值引用变量仍然是左值表达式

```cpp
Student(Student&& other) noexcept
    : name(std::move(other.name))
{
}
```

虽然 `other` 的声明类型为 `Student&&`，但表达式 `other` 有名字，因此是左值表达式。`other.name` 同样是左值表达式。

如果写成：

```cpp
name = other.name;
```

通常会调用 `std::string` 的复制赋值。

如果希望移动成员，应明确写成：

```cpp
name = std::move(other.name);
```

**记忆要点：** 引用的声明类型与表达式的值类别不是一回事。

## 3. 移动构造与移动赋值不能混淆

```cpp
Student student2 = std::move(student1);
```

`student2` 正在初始化，是移动构造场景。

```cpp
student3 = std::move(student2);
```

`student3` 已经存在，是移动赋值场景。

**判断方法：** 看目标对象是否正在被创建，而不是只看有没有 `std::move`。

## 4. 移动赋值的返回值应为当前对象引用

正确写法：

```cpp
Student& operator=(Student&& other) noexcept
{
    name = std::move(other.name);
    return *this;
}
```

其中：
- `this` 是指向当前对象的指针。
- `*this` 表示当前对象本身。
- `return *this` 返回当前对象的引用，符合 `Student&` 的返回类型。
- 返回当前对象的引用也支持链式赋值。

不要误写为：

```cpp
return other;
```

`other` 是源对象，而移动赋值运算符应返回目标对象的引用。

## 5. 声明移动构造函数后，不要假设移动赋值运算符会自动生成

例如：

```cpp
Student(Student&& other) noexcept
    : name(std::move(other.name))
{
}
```

显式声明移动构造函数后，编译器不会自动生成移动赋值运算符。

对于需要默认移动赋值的类，可以明确声明：

```cpp
Student& operator=(Student&& other) noexcept = default;
```

注意：类中其他特殊成员函数的声明也会影响编译器对特殊成员函数的隐式生成规则。

## 6. `= default` 不会执行自定义函数体

自定义实现：

```cpp
Student& operator=(Student&& other) noexcept
{
    std::cout << "Move Assignment\n";
    name = std::move(other.name);
    return *this;
}
```

默认实现：

```cpp
Student& operator=(Student&& other) noexcept = default;
```

切换到 `= default` 后，自己编写的日志不会出现，因为自定义函数体已不存在。

**避免误判：** 不要因为看不到 `Move Assignment` 就认为移动赋值没有发生，应检查赋值后的对象状态。

## 7. 移动后的对象不保证为空

本次实验中，移动后的 `std::string` 在当前运行环境下显示为空。

但标准不保证移动后的字符串一定为空。对标准库类型而言，移动后的对象通常仍处于有效但未指定的状态；对于自定义类型，则要看具体操作的约定。

因此，不要把以下输出当成所有移动操作的固定结果：

```text
student1:
student2:
```

更稳妥的方式是检查目标对象是否正确获得所需数据，并遵循源类型规定的移动后状态。

## 8. `noexcept` 是异常承诺，不是启用移动的开关

```cpp
Student(Student&& other) noexcept;
```

`noexcept` 表示该函数承诺不抛出异常，并不是移动操作成立的必要条件。

标准库容器在扩容等场景下，可能根据移动构造是否不抛异常来选择合适的操作策略。因此，只有当实现确实能够保证不抛异常时，才应声明 `noexcept`。

## 9. 忘记包含必要头文件

本次实践涉及以下头文件：

```cpp
#include <iostream>
#include <string>
#include <memory>
#include <utility>
```

用途：
- `<iostream>`：输入输出。
- `<string>`：字符串成员。
- `<memory>`：`std::unique_ptr`、`std::make_unique` 等智能指针功能。
- `<utility>`：`std::move` 等工具。

不要依赖其他头文件间接包含所需声明。

## 10. 构建结果与源码不一致时，不要立刻判断移动语义错误

如果运行后没有看到预期日志，或输出与刚修改的代码不符，应依次检查：

1. 当前运行的是不是预期的可执行文件。
2. 修改的源文件是否属于当前 CMake 目标。
3. 是否成功重新编译。
4. 日志是否已随自定义函数体被删除。
5. 当前输出是否确实能证明操作未发生。

**排查原则：** 先核实源码、目标和运行产物，再分析 C++ 语义问题。