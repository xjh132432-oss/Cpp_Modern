# Day04 - std::weak_ptr

## 一、学习目标

理解 C++ `std::weak_ptr` 的基本用法，掌握弱引用、`lock()`、`expired()`，并理解 `weak_ptr` 如何帮助避免 `shared_ptr` 循环引用。

## 二、学习内容

### 1. 创建 weak_ptr

使用 `weak_ptr` 观察由 `shared_ptr` 管理的对象。

```cpp
auto student = std::make_shared<Student>();
student->name = "Alice";

std::weak_ptr<Student> weak = student;
```

需要的头文件：

```cpp
#include <memory>
```

`weak_ptr` 不拥有对象，不会增加 `shared_ptr` 的引用计数。

### 2. 使用 use_count()

```cpp
std::cout << student.use_count() << '\n';
```

创建 `weak_ptr` 后，原有的共享引用计数不会因为弱引用而增加。

### 3. 使用 lock() 安全访问对象

`weak_ptr` 不能直接使用 `->` 访问对象，需要先调用 `lock()` 获取一个 `shared_ptr`。

```cpp
auto student2 = weak.lock();

if (student2)
{
    std::cout << student2->name << '\n';
}
```

- 对象仍然存在时，`lock()` 返回有效的 `shared_ptr`。
- 对象已经销毁时，`lock()` 返回空的 `shared_ptr`。
- 成功获取共享指针后，引用计数会增加；临时共享指针销毁后，引用计数相应减少。

### 4. 使用 expired() 检查对象状态

```cpp
if (weak.expired())
{
    std::cout << "Object expired\n";
}
```

`expired()` 返回 `true` 表示弱引用对应的对象已经不存在。

### 5. 理解对象生命周期

当最后一个持有对象的 `shared_ptr` 被销毁或释放所有权时，对象才会销毁。

即使对象已经销毁，`weak_ptr` 本身仍可以存在，但不能再通过它获取原对象。

## 三、实践记录

- [x] 创建 `std::weak_ptr<Student>`。
- [x] 验证创建弱引用不会增加共享引用计数。
- [x] 使用 `lock()` 获取共享智能指针。
- [x] 通过 `lock()` 返回值判断对象是否可以访问。
- [x] 使用 `expired()` 检查对象状态。
- [x] 通过作用域理解共享所有者释放与对象销毁之间的关系。

## 四、核心知识总结

| 接口或概念 | 作用 |
|---|---|
| `std::weak_ptr<T>` | 观察共享对象，不拥有对象 |
| `lock()` | 尝试获取一个共享所有者 |
| `expired()` | 判断对象是否已经失效 |
| `use_count()` | 查询当前共享所有者数量 |
| `shared_ptr` | 通过共享所有权管理对象生命周期 |

## 五、与循环引用的关系

如果两个对象通过 `shared_ptr` 相互持有对方，即使外部所有者释放，也可能因为引用计数不为零而无法销毁。

将适合的一侧改为 `weak_ptr`，可以避免这类循环所有权问题。

注意：本日重点是 `weak_ptr` 基本使用与对象生命周期。完整的双对象循环引用示例可作为后续进阶实践。

## 六、编译运行

在当前项目配置对应的构建目录中编译运行。

如果 `day04_weak_ptr` 目录包含独立的 `CMakeLists.txt`，可以使用：

```bash
cmake -S . -B build
cmake --build build
```

如果使用仓库根目录的 CMake 工程，请根据实际项目结构选择对应的构建目录。

## 七、下一步

完成 `weak_ptr` 的基本使用后，进一步学习循环引用的实际成因，以及如何通过弱引用设计对象之间的关系。
