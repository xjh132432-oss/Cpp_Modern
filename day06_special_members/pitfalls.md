# Day06 Pitfalls：特殊成员函数与对象生命周期

## 1. 通过析构日志确认对象销毁顺序

### 现象

最初的析构函数只输出 `Destructor`，无法直接从日志判断具体是哪个对象被销毁。

### 解决方法

修改析构函数，输出对象的 `name`：

    ~Student()
    {
        std::cout << "Destructor: " << name << '\n';
    }

### 验证结果

    Destructor: Alice
    Destructor: Charlie
    Destructor: Alice

根据对象的创建顺序和名字，可以确认 `c`、`b`、`a` 依次析构。

## 2. 验证对象复制后的独立性

### 实验过程

将 `b.name` 修改为 `Charlie`，再观察三个对象的名字及析构日志。

### 验证结果

- `a.name` 仍为 `Alice`。
- `b.name` 变为 `Charlie`。
- `c.name` 仍为 `Alice`。

这说明本次拷贝构造和拷贝赋值后，三个对象各自拥有独立的 `std::string` 成员。