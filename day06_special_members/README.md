# Day06：C++ 特殊成员函数与对象生命周期

## 一、学习目标

通过 `Student` 类的实际编程，理解对象的创建、复制、赋值和销毁过程，掌握以下知识：

- 默认构造函数与析构函数
- 拷贝构造函数（Copy Constructor）
- 拷贝赋值运算符（Copy Assignment Operator）
- `this`、`*this` 与自我赋值检查
- 对象独立性与局部对象的析构顺序
- 初始化列表的基本写法

## 二、核心知识

### 1. 拷贝构造与拷贝赋值

两者都可以复制对象的数据，但调用时机不同。

**拷贝构造：创建新对象时复制已有对象**

    Student a;
    a.name = "Alice";
    Student b = a;

`b` 是新创建的对象，因此调用拷贝构造函数。

    Student(const Student& other)
        : name(other.name)
    {
        std::cout << "Copy Constructor\n";
    }

`const Student& other` 通过常量引用接收源对象，避免再次复制整个对象；初始化列表 `: name(other.name)` 直接使用源对象的 `name` 初始化当前对象的成员。

**拷贝赋值：已有对象接收另一个对象的数据**

    Student c;
    c.name = "Bob";
    c = a;

`c` 已经存在，因此调用拷贝赋值运算符，而不是拷贝构造函数。

    Student& operator=(const Student& other)
    {
        std::cout << "Copy Assignment\n";

        if (this == &other)
            return *this;

        this->name = other.name;
        return *this;
    }

关键点：

- `this` 是指向当前对象的指针。
- `&other` 是源对象的地址。
- `this == &other` 用于检测自我赋值，例如 `a = a`。
- `this->name` 表示当前对象的 `name` 成员。
- `*this` 表示当前对象本身。
- 返回类型 `Student&` 允许赋值表达式返回当前对象的引用。

### 2. 构造函数与析构函数

构造函数在对象创建时执行，析构函数在对象生命周期结束时执行。

    Student()
    {
        std::cout << "Default Constructor\n";
    }

    ~Student()
    {
        std::cout << "Destructor: " << name << '\n';
    }

`main()` 中的局部对象离开作用域时，会按照构造顺序的逆序析构。

### 3. 对象独立性

执行 `Student b = a;` 会复制 `a` 的 `name`，但不会让 `a` 和 `b` 变成同一个对象。

    b.name = "Charlie";

修改 `b.name` 不会自动改变 `a.name`。本次实验中，`b` 在析构时输出 `Charlie`，而 `a`、`c` 输出 `Alice`，验证了这一点。

### 4. 初始化列表

拷贝构造函数可以使用初始化列表：

    Student(const Student& other)
        : name(other.name)
    {
        std::cout << "Copy Constructor\n";
    }

初始化列表在构造函数体执行之前初始化成员。对于具有构造逻辑的成员，这通常比先默认构造、再在函数体内赋值更直接。

## 三、实操内容

本次实现位于 `day06_special_members` 目录。

### 1. `student.h`

实现了以下特殊成员函数：

| 成员函数 | 作用 |
|---|---|
| `Student()` | 默认构造对象 |
| `~Student()` | 在对象销毁时输出日志 |
| `Student(const Student& other)` | 使用已有对象创建新对象 |
| `operator=(const Student& other)` | 将数据复制到已有对象 |

### 2. `main.cpp`

实操按照以下顺序进行：

1. 创建对象 `a`，将名字设为 `Alice`。
2. 执行 `Student b = a`，验证拷贝构造。
3. 创建对象 `c`，将名字设为 `Bob`。
4. 执行 `c = a`，验证拷贝赋值。
5. 打印对象名字，验证复制结果。
6. 修改 `b.name` 为 `Charlie`，验证对象之间的数据独立性。
7. 观察对象离开 `main()` 时的析构日志。

## 四、验证结果

运行结果验证了以下现象：

- 创建 `a`、`c` 时，调用默认构造函数。
- 创建 `b` 时，调用拷贝构造函数。
- 执行 `c = a` 时，调用拷贝赋值运算符。
- 赋值后，三个对象的名字均为 `Alice`。
- 修改 `b.name` 不会改变 `a.name` 和 `c.name`。
- 离开 `main()` 后，三个局部对象按构造顺序的逆序析构。

最终析构日志为：

    Destructor: Alice
    Destructor: Charlie
    Destructor: Alice

根据对象的创建顺序，对应的析构对象依次为 `c`、`b`、`a`。

## 五、本日总结

Day06 的核心是区分**创建对象时的复制**与**已有对象的赋值**，并通过构造、赋值和析构日志观察对象的生命周期。

需要记住：

- `Student b = a;` 是拷贝构造。
- `b = a;` 在 `b` 已经存在时是拷贝赋值。
- `this` 是当前对象的指针，`*this` 是当前对象本身。
- 局部对象离开作用域时自动析构，析构顺序与构造顺序相反。
- `std::string` 会自行管理字符串资源，因此本例不需要手动申请和释放内存。

本日为后续理解移动语义、特殊成员函数生成规则以及 C++ 类资源管理打下基础。