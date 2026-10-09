# Workflow — Day02

## 今日任务

学习并实践 C++ 智能指针 `std::unique_ptr`。

## 实际完成

- [x] 复习普通指针与堆对象的生命周期
- [x] 理解 `new` / `delete` 与内存泄漏
- [x] 初步理解 RAII
- [x] 引入 `<memory>` 并使用 `std::unique_ptr`
- [x] 使用 `std::make_unique<Student>()` 创建对象
- [x] 通过 `student->name` 等方式访问成员
- [x] 通过析构函数输出验证对象自动释放
- [x] 对比普通指针与智能指针的生命周期
- [x] 验证 `unique_ptr` 不支持复制
- [x] 使用 `std::move` 转移所有权
- [x] 观察移动后的指针状态及对象销毁时机

## 遇到的问题与解决

### 问题一：找不到 `std::unique_ptr`

原因：缺少 `<memory>` 头文件。

解决：添加 `#include <memory>`。

### 问题二：`make_unique` 无法匹配 Student 构造函数

原因：`Student` 没有接受三个参数的构造函数。

解决：先使用默认构造，再给 `name`、`age` 和 `score` 赋值。

### 问题三：复制 unique_ptr 失败

原因：`unique_ptr` 禁止复制，以保证独占所有权。

解决：使用 `std::move` 转移所有权。

## 当前状态

Day02 的 `unique_ptr` 核心实践已完成，后续可以继续巩固 RAII、对象生命周期和所有权管理。

## Git 提交

建议提交信息：

```text
feat(day02): learn unique_ptr and RAII
```
