# Day05 — Move Semantics Workflow

## 1. 学习目标

- 理解 `std::move` 与右值引用的关系。
- 区分移动构造函数和移动赋值运算符。
- 掌握 `unique_ptr` 的所有权转移。
- 理解 `= default`、`noexcept` 的用途。
- 通过编写、编译、运行、对比输出完成验证。

## 2. 实践过程

### 2.1 unique_ptr 所有权转移

使用 `std::make_unique<Student>()` 创建对象，并使用 `std::move` 转移所有权。

```cpp
auto student1 = std::make_unique<Student>();
student1->name = "Alice";

auto student2 = std::move(student1);

if (!student1)
    std::cout << "1empty\n";

if (student2)
    std::cout << student2->name << '\n';
```

验证结果：
- `student1` 转移后为空。
- `student2` 接管对象所有权，可以正常访问成员。

### 2.2 实现移动构造函数

在 `Student` 类中实现移动构造函数：

```cpp
Student(Student&& other) noexcept
    : name(std::move(other.name))
{
    std::cout << "Move Constructor\n";
}
```

通过以下操作触发移动构造：

```cpp
Student student2 = std::move(student1);
```

观察构造函数输出，并检查目标对象的成员是否正确获取数据。

### 2.3 实现移动赋值运算符

先手动实现移动赋值：

```cpp
Student& operator=(Student&& other) noexcept
{
    this->name = std::move(other.name);
    return *this;
}
```

再将其替换为默认实现：

```cpp
Student& operator=(Student&& other) noexcept = default;
```

使用以下操作验证：

```cpp
student3 = std::move(student2);
```

对比两种实现：
- 自定义版本可以输出自己编写的 `Move Assignment` 日志。
- 默认版本不会输出该自定义日志，但仍然可以完成成员的移动赋值。

### 2.4 验证移动后的对象状态

执行移动构造与移动赋值后，分别打印 `student1`、`student2` 和 `student3` 的 `name`。

使用默认移动赋值时，实验输出为：

```text
--- Move Construction ---
Move Constructor
--- Move Assignment ---
student1:
student2:
student3: Alice
```

本次运行中，移动后的源字符串为空，目标对象最终持有 `Alice`。

注意：移动后源对象仍然有效，但其具体状态取决于类型和操作。不能依赖所有移动操作都会将源对象清空。

## 3. 编译与运行

在项目根目录执行：

```bash
cmake -S . -B build
cmake --build build
./build/move1
```

验证事项：
- CMake 配置与编译是否成功。
- 移动构造是否触发。
- 自定义移动赋值和默认移动赋值的输出差异是否符合预期。
- 最终成员数据是否正确。
- 当前输出是否与修改后的源码一致。

如果项目的可执行文件名称或生成目录不同，应以实际 `CMakeLists.txt` 配置为准。

## 4. 整理学习记录

检查并更新以下文件：

- `README.md`：记录 Day05 的核心知识点，不重复完整实践流程。
- `workflow.md`：记录当天实践步骤、运行验证、问题修正和 Git 操作。
- `pitfalls.md`：单独记录易错点及其原因。

确认源码、构建配置和文档均与当前实现一致。

## 5. Git 提交流程

### 5.1 检查工作区

```bash
git status
git diff
```

确认本次实际修改的文件及代码差异。

### 5.2 暂存文件

```bash
git add README.md workflow.md pitfalls.md move.h main.cpp CMakeLists.txt
```

如果本次还修改了其他文件，按实际情况调整暂存列表。

### 5.3 检查暂存区

```bash
git diff --cached
```

确认只包含本次需要提交的代码和文档，不包含构建产物或无关文件。

### 5.4 提交并复查

```bash
git commit -m "Complete Day05 move semantics"
git status
```

确认提交成功，并检查是否还有未提交修改。

## 6. 完成检查

- [ ] 理解 `std::move` 的作用。
- [ ] 能区分移动构造与移动赋值。
- [ ] 完成 `unique_ptr` 所有权转移实验。
- [ ] 完成移动构造函数实践。
- [ ] 对比手动移动赋值与 `= default`。
- [ ] 成功编译并运行程序。
- [ ] 更新 `README.md`、`workflow.md`、`pitfalls.md`。
- [ ] 检查暂存区并完成 Git 提交。