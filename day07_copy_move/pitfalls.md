# Day07 Pitfalls

## 1. 赋值运算符按值返回，导致额外拷贝

### 问题代码

    Student operator=(const Student& other)
    Student operator=(Student&& other) noexcept

### 实际现象

执行 `d = b` 和 `d = std::move(b)` 时，除了对应的赋值日志，还额外出现了：

    Copy Constructor
    Destructor: Alice

### 原因

赋值运算符的返回类型是 `Student`，即按值返回对象。

执行 `return *this;` 时，需要产生一个返回对象，因此出现额外的拷贝构造和临时对象析构。

### 修正方法

将两个赋值运算符的返回类型都改为 `Student&`，并保留 `return *this;`。

    Student& operator=(const Student& other);
    Student& operator=(Student&& other) noexcept;

### 验证状态

已通过实际运行发现问题；修改后的代码及重新运行结果尚待确认。
