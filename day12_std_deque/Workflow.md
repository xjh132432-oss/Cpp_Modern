# Day12 Workflow

## 1. 项目结构

    day12_std_deque/
    ├── 01_deque_basics/
    │   ├── CMakeLists.txt
    │   └── main.cpp
    ├── 02_deque_operations/
    │   ├── CMakeLists.txt
    │   └── main.cpp
    ├── 03_container_comparison/
    │   ├── CMakeLists.txt
    │   └── main.cpp
    ├── README.md
    ├── workflow.md
    └── pitfalls.md

## 2. 实际完成内容

- [x] 创建 `std::deque<int>`。
- [x] 使用 `push_front()` 和 `push_back()` 插入元素。
- [x] 使用 `pop_front()` 和 `pop_back()` 删除元素。
- [x] 使用 `front()` 和 `back()` 获取首尾元素。
- [x] 使用 `size()`、`operator[]` 和 `at()`。
- [x] 使用迭代器遍历 deque。
- [x] 完成连续双端插入与删除实验。
- [x] 创建 vector、list、deque 三种容器进行对比。
- [x] 验证 vector 和 deque 支持下标访问。
- [x] 验证 list 不支持 `operator[]`。
- [x] 使用 `std::next()` 访问 list 的第三个元素。
- [x] 理解 deque 的分段连续存储结构。
- [x] 对比三种容器的基本操作复杂度和适用场景。

## 3. 构建与运行

每个实验目录独立构建：

    cmake -S . -B build
    cmake --build build
    ./build/可执行文件名称

本日使用 C++17 完成实验。

## 4. Git 提交

建议提交信息：

    feat: complete Day12 std::deque practice

提交前按照以下顺序执行：

    git status
    git diff

    git add day12_std_deque/

    git diff --cached

    git commit -m "feat: complete Day12 std::deque practice"

    git status
    git push