# Day12 Pitfalls

## 1. list 不支持下标访问

**遇到的问题：**

在三种容器对比实验中，使用 `l[2]` 访问 list 的第三个元素，编译时报错：

    error: no match for 'operator[]'
    (operand types are 'std::__cxx11::list<int>' and 'int')

**原因：**

list 是双向链表，节点之间通过指针连接，不支持随机访问，因此没有 `operator[]`。

**解决方法：**

使用 `std::next()` 移动迭代器：

    *std::next(l.begin(), 2)

同时包含 `<iterator>`。

## 2. operator[] 与 at() 的区别

**本日学习中需要注意：**

- `operator[]` 不进行边界检查。
- `at()` 进行边界检查，越界会抛出 `std::out_of_range` 异常。

使用下标访问时，应确保索引处于有效范围内。

## 3. 双端删除前检查容器状态

`pop_front()` 和 `pop_back()` 不负责检查容器是否为空。

调用前应通过 `empty()` 判断，避免对空容器执行删除操作。

## 4. 本日记录

本日实际遇到的编译问题是 list 不支持下标访问。其余内容属于学习过程中需要掌握的 API 使用注意事项，不记录为实际发生的程序错误。