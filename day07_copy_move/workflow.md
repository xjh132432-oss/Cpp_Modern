# Day07 Workflow

## 1. 创建项目

- [x] 创建 `day07_copy_move` 目录。
- [x] 创建 `CMakeLists.txt`。
- [x] 创建 `student.h`。
- [x] 创建 `main.cpp`。

## 2. 实现功能

- [x] 实现默认构造函数。
- [x] 实现析构函数并输出对象名称。
- [x] 实现拷贝构造函数。
- [x] 实现拷贝赋值运算符。
- [x] 实现移动构造函数。
- [x] 实现移动赋值运算符。
- [x] 使用 `std::move` 测试移动操作。

## 3. 编译与运行

- [x] 使用 CMake 构建项目。
- [x] 运行程序并观察四种操作的日志。
- [x] 观察移动后对象的字符串状态。
- [x] 发现赋值运算符按值返回导致额外拷贝构造和临时对象析构。

## 4. 待完成的修正与复验

- [ ] 将拷贝赋值返回类型改为 `Student&`。
- [ ] 将移动赋值返回类型改为 `Student&`。
- [ ] 将移动操作日志名称改为 `Move Constructor` 和 `Move Assignment`。
- [ ] 重新编译并运行。
- [ ] 检查赋值操作是否不再因按值返回而产生额外的拷贝构造。
- [ ] 检查最终输出和对象析构顺序。

## 5. Git 提交

修正与复验完成后，按以下顺序执行：

1. `git status`
2. `git diff`
3. `git add day07_copy_move`
4. `git diff --cached`
5. `git commit -m "feat: practice C++ copy and move semantics"`
6. `git status`
7. `git push`

只勾选实际完成的操作，不提前记录未验证的结果。
