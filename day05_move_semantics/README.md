# Day05：C++ 移动语义

## 一、学习目标

- 理解 `std::move` 与右值引用。
- 掌握 `unique_ptr` 所有权转移。
- 区分移动构造与移动赋值。
- 理解 `= default`、`noexcept` 的作用。

## 二、核心知识点

### 1. `std::move`

`std::move` 定义于 `<utility>`，本质上是类型转换，不直接移动数据，而是使表达式可以参与移动操作的重载选择。

```cpp
Student student2 = std::move(student1);
```

注意：有名字的变量即使类型是右值引用，直接使用时仍是左值表达式。

```cpp
Student(Student&& other)
    : name(std::move(other.name)) {}
```

这里仍需对 `other.name` 使用 `std::move`，才能让 `std::string` 选择移动构造。

### 2. 移动构造与移动赋值

```cpp
// 移动构造：创建新对象
Student student2 = std::move(student1);

// 移动赋值：修改已有对象
student2 = std::move(student1);
```

移动构造函数：

```cpp
Student(Student&& other) noexcept
    : name(std::move(other.name)) {}
```

移动赋值运算符：

```cpp
Student& operator=(Student&& other) noexcept
{
    name = std::move(other.name);
    return *this;
}
```

- `Student&&`：接收右值引用。
- `std::move`：允许成员参与移动操作。
- `*this`：当前对象，返回 `Student&` 可支持链式赋值。

### 3. `unique_ptr` 所有权转移

```cpp
auto student1 = std::make_unique<Student>();
auto student2 = std::move(student1);
```

移动后，`student2` 接管所有权，`student1` 为空。`unique_ptr` 不支持普通复制，因为它管理独占所有权。

### 4. `= default`

```cpp
Student& operator=(Student&& other) noexcept = default;
```

要求编译器生成默认实现。对于包含 `std::string` 成员的 `Student`，默认移动赋值可以正确处理该成员，但不会保留自定义函数体中的输出语句。

声明移动构造函数后，编译器不会自动生成移动赋值运算符；需要时可自行实现或使用 `= default`。

### 5. `noexcept`

```cpp
Student(Student&& other) noexcept;
```

表示函数承诺不抛出异常。它不是启用移动语义的条件：即使没有 `noexcept`，移动构造仍然可以调用。

`noexcept` 会影响异常安全及部分标准库容器的操作策略，例如 `std::vector` 扩容时对移动和复制的选择。

只有在确实不会抛出异常时，才应声明 `noexcept`。

### 6. 移动后的对象状态

移动后的源对象通常仍然有效，但具体状态取决于类型及操作的保证。

本次实验中，移动后的 `std::string` 变为空字符串，但标准不保证移动后一定为空。不要依赖未明确保证的源对象内容。

## 三、实验总结

- `std::move` 不直接转移资源，而是转换表达式的值类别。
- 移动构造用于初始化新对象，移动赋值用于修改已有对象。
- `unique_ptr` 移动会转移独占所有权。
- `= default` 可使用编译器生成的默认实现。
- `noexcept` 表示不抛出异常的承诺。
- 移动后的对象仍可销毁或重新赋值，但不能随意假设其状态。

## 四、构建运行

```bash
cmake -S . -B build
cmake --build build
./build/move1
```