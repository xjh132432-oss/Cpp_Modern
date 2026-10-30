# Day11 Workflow

## 1. 项目结构

    day11_std_list/
    ├── 01_list_basics/
    │   ├── CMakeLists.txt
    │   └── main.cpp
    ├── 02_list_insert_erase/
    │   ├── CMakeLists.txt
    │   └── main.cpp
    ├── 03_vector_vs_list/
    │   ├── CMakeLists.txt
    │   └── main.cpp
    ├── README.md
    ├── workflow.md
    └── pitfalls.md

## 2. 实际完成内容

- [x] 创建 `std::list<int>`，完成基础初始化。
- [x] 使用 `push_back()` 和 `push_front()` 插入元素。
- [x] 使用 `front()`、`back()` 和 `size()` 获取链表信息。
- [x] 使用迭代器遍历 `list`。
- [x] 使用 `insert()` 在指定位置插入元素。
- [x] 使用 `erase()` 删除指定节点。
- [x] 验证 `list` 插入节点不会使其他迭代器失效。
- [x] 使用 `erase()` 返回值安全删除偶数。
- [x] 学习 `std::next()` 和 `std::prev()`。
- [x] 对比 `vector` 与 `list` 的迭代器失效规则。
- [x] 验证 `vector` 插入后原有迭代器失效的问题。
- [x] 重新获取有效的 `vector` 迭代器并完成删除。
- [x] 验证两个容器最终输出结果一致。

## 3. 构建与运行

每个实验目录独立构建，进入对应目录后执行：

    cmake -S . -B build
    cmake --build build
    ./build/可执行文件名称

本日使用 C++17 完成实验。

## 4. Git 提交

建议提交信息：

    feat: complete Day11 std::list practice

提交前按照以下顺序检查：

    git status
    git diff

    git add day11_std_list/

    git diff --cached

    git commit -m "feat: complete Day11 std::list practice"

    git status
    git push