# Day06 Workflow：特殊成员函数与对象生命周期

## 一、学习目标

通过 `day06_special_members` 实践拷贝构造、拷贝赋值和对象析构，理解对象的复制行为与生命周期。

## 二、实际完成内容

- [x] 创建 `day06_special_members` 学习目录。
- [x] 编写 `student.h`，引入 `<string>` 和 `<iostream>`。
- [x] 实现默认构造函数，并输出构造日志。
- [x] 实现析构函数，输出对象销毁时的 `name`。
- [x] 实现拷贝构造函数 `Student(const Student& other)`。
- [x] 实现拷贝赋值运算符 `Student& operator=(const Student& other)`。
- [x] 在拷贝赋值中检查自我赋值，并返回 `*this`。
- [x] 在 `main.cpp` 中创建对象 `a`、`b`、`c`。
- [x] 使用 `Student b = a` 验证拷贝构造。
- [x] 使用 `c = a` 验证拷贝赋值。
- [x] 修改 `b.name` 为 `Charlie`，验证对象之间的数据独立性。
- [x] 运行程序，检查构造、赋值和析构日志。
- [x] 验证局部对象按照构造顺序的逆序析构。

## 三、验证结果

- `a` 和 `c` 的名字保持为 `Alice`，`b` 修改后为 `Charlie`。
- 创建新对象时调用拷贝构造函数。
- 为已有对象赋值时调用拷贝赋值运算符。
- 程序结束时，`c`、`b`、`a` 依次析构。
- 析构日志依次输出 `Alice`、`Charlie`、`Alice`。

## 四、Git 提交流程

在 `Cpp_Modern` 仓库根目录执行以下操作。

1. 检查工作区状态：

   `git status`

2. 查看未暂存的修改：

   `git diff`

3. 添加本次 Day06 实际完成的文件：

   `git add day06_special_members`

4. 检查暂存区内容：

   `git diff --cached`

5. 提交：

   `git commit -m "Complete Day06 special member functions"`

6. 检查提交后的工作区：

   `git status`

7. 推送到远程仓库：

   `git push`

提交前确认 `README.md`、`workflow.md`、`pitfalls.md` 及源码均已按实际完成情况保存，并检查暂存区没有无关文件。