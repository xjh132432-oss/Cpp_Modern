# Day02 — Smart Pointers: `std::unique_ptr`

## 1. 学习目标

理解 C++ 智能指针的基本用途，掌握 `std::unique_ptr` 的创建、访问、自动释放和所有权转移。

本日重点：

- 理解普通指针与堆对象的生命周期
- 理解 `new` / `delete` 与内存泄漏
- 理解 RAII 的基本思想
- 使用 `std::make_unique` 创建智能指针
- 理解 `unique_ptr` 的独占所有权
- 使用 `std::move` 转移所有权

## 2. 项目环境

- 语言：C++
- 编译工具：GCC / MinGW
- 构建工具：CMake
- IDE：VS Code
- 练习对象：`Student`

## 3. 核心知识

### 3.1 普通指针与内存泄漏

```cpp
void testRawPointer()
{
    Student* student = new Student;
    student->name = "Alice";

    // 函数结束时，局部指针销毁，
    // 但堆上的 Student 不会自动释放。
}
```

`student` 是局部指针变量，`new` 创建的 `Student` 是动态分配的对象。

函数结束后，指针变量离开作用域，但如果没有释放对象，就可能发生内存泄漏。

### 3.2 创建 unique_ptr

```cpp
#include <memory>

auto student = std::make_unique<Student>();

student->name = "Alice";
student->age = 20;
student->score = 90.5;
```

`std::make_unique<Student>()` 创建一个 `Student` 对象，并返回管理该对象的 `std::unique_ptr<Student>`。

使用 `student->name` 访问成员，与普通指针的访问语法相似。

### 3.3 RAII 与自动释放

RAII 的核心思想是将资源的管理与对象的生命周期绑定。

当局部 `unique_ptr` 离开作用域时，它的析构函数会释放其拥有的 `Student` 对象。

因此，正常情况下不需要手动调用 `delete`。

通过给 `Student` 添加析构函数，可以观察对象销毁的时间：

```cpp
~Student()
{
    std::cout << "Student destroyed\n";
}
```

实验观察：`Student destroyed` 出现在函数结束之后、调用方继续执行之前。

### 3.4 独占所有权

`unique_ptr` 表示独占所有权。同一个对象不能由两个 `unique_ptr` 同时独占管理。

```cpp
auto student = std::make_unique<Student>();

// auto student2 = student;  // 编译失败
```

`unique_ptr` 不支持复制，但支持移动。

### 3.5 使用 std::move 转移所有权

```cpp
#include <memory>
#include <utility>

auto student = std::make_unique<Student>();
student->name = "Alice";

auto student2 = std::move(student);
```

移动之后：

- `student` 不再拥有原来的对象，通常为空。
- `student2` 获得对象的所有权。
- 对象不会因为所有权转移而立即销毁。
- 当 `student2` 离开作用域时，对象自动释放。

`std::move` 使表达式可以参与移动操作，本身不负责释放对象。

## 4. 实验记录

### 实验一：普通指针

观察函数结束后，局部指针与动态分配对象的生命周期区别。

结论：普通指针离开作用域，不代表它指向的堆对象会自动销毁。

### 实验二：unique_ptr 自动释放

使用 `std::make_unique` 创建 `Student`，通过析构函数输出观察对象的销毁时机。

结论：`unique_ptr` 离开作用域时会自动释放自己拥有的对象。

### 实验三：独占所有权与移动

尝试复制 `unique_ptr`，观察编译错误；再使用 `std::move` 转移所有权。

结论：`unique_ptr` 不允许复制所有权，但允许转移所有权。

## 5. 常见问题

### 问题一：`std::unique_ptr` 未定义

原因：缺少头文件。

解决：

```cpp
#include <memory>
```

### 问题二：`make_unique` 无法构造 Student

原因：当前 `Student` 没有匹配传入参数的构造函数。

解决：如果暂时不学习构造函数，可以先使用默认构造，再给成员赋值：

```cpp
auto student = std::make_unique<Student>();
student->name = "Alice";
student->age = 20;
student->score = 90.5;
```

### 问题三：复制 unique_ptr 编译失败

原因：`unique_ptr` 的复制操作被禁止。

解决：需要转移所有权时使用 `std::move`。

## 6. 本日总结

本日掌握：

- 普通指针与堆对象的生命周期区别
- 内存泄漏的基本成因
- RAII 的基本思想
- `unique_ptr` 的创建和成员访问
- 智能指针离开作用域后的自动释放
- 独占所有权与 `std::move`

后续继续学习其他现代 C++ 资源管理机制，并通过实际代码巩固所有权和对象生命周期的理解。
