# Day03 — std::shared_ptr

## 学习目标

理解 C++ 智能指针 `std::shared_ptr` 的基本使用，掌握多个智能指针共享同一个对象时的所有权变化与对象生命周期管理。

## 学习内容

### 1. 创建 shared_ptr

通过 `std::make_shared<T>()` 创建对象，并由智能指针管理其生命周期。

```cpp
#include <memory>

auto student1 = std::make_shared<Student>();
student1->name = "Alice";
```

- `std::make_shared<Student>()` 创建一个 `Student` 对象。
- `student1` 持有该对象的共享所有权。
- 使用 `->` 访问对象成员。

### 2. 共享所有权与引用计数

```cpp
auto student2 = student1;

std::cout << student1.use_count() << '\n';
std::cout << student2.use_count() << '\n';
```

实验输出：

```text
2
2
```

`student1` 和 `student2` 指向同一个对象，共同拥有它，因此两者查询到的引用计数均为 `2`。

注意：`use_count()` 表示当前共享所有者的数量，不是某个智能指针独立拥有的计数。

### 3. 作用域与对象生命周期

```cpp
auto student1 = std::make_shared<Student>();

{
    auto student2 = student1;
    std::cout << student1.use_count() << '\n';
}

std::cout << student1.use_count() << '\n';
```

实验结果：

```text
1
2
1
```

- 创建 `student1` 后，引用计数为 `1`。
- 创建 `student2` 后，引用计数变为 `2`。
- 离开内部作用域，`student2` 被销毁，引用计数恢复为 `1`。
- `student1` 仍然持有对象，因此对象不会提前销毁。

当最后一个持有对象的 `shared_ptr` 被销毁或释放所有权时，对象才会被销毁。

### 4. 多个指针访问同一个对象

```cpp
auto student2 = student1;
student2->name = "Bob";

std::cout << student1->name << '\n';
```

实验输出：

```text
Bob
```

这证明两个智能指针访问的是同一个 `Student` 对象，而不是各自保存一份独立的对象副本。

### 5. 函数参数与引用计数

```cpp
void printStudent(std::shared_ptr<Student> student)
{
    std::cout << student->name << '\n';
    std::cout << student.use_count() << '\n';
}
```

调用：

```cpp
printStudent(student1);
std::cout << student1.use_count() << '\n';
```

实验输出：

```text
Alice
2
1
```

按值传递 `shared_ptr` 会复制智能指针并共享对象所有权。函数执行期间引用计数增加；函数返回后，参数被销毁，引用计数恢复。

## 与 unique_ptr 的区别

| 对比项 | `unique_ptr` | `shared_ptr` |
|---|---|---|
| 所有权 | 独占所有权 | 共享所有权 |
| 普通复制 | 不允许 | 允许 |
| `std::move` | 转移独占所有权 | 转移当前智能指针持有的所有权 |
| 对象销毁 | 独占所有者释放后 | 最后一个共享所有者释放后 |

## 本日总结

- 掌握 `std::make_shared` 的基本使用。
- 理解 `use_count()` 的含义。
- 验证多个 `shared_ptr` 可以访问同一个对象。
- 理解函数按值接收 `shared_ptr` 时的引用计数变化。
- 理解作用域结束、智能指针销毁与对象生命周期之间的关系。

## 下一步

继续学习 `std::weak_ptr`，理解不增加共享引用计数的观察方式，以及如何处理循环引用问题。