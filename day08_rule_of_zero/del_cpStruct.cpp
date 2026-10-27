#include <iostream>
#include <utility>
#include "student.h"

int main()
{
    Student a;
    a.name = "alice";
    a.age = 17;

    // 移动构造
    Student b = std::move(a);

    std::cout << "b.name: " << b.name << '\n';
    std::cout << "a.name after move: " << a.name << '\n';

    Student c;
    c.name = "bob";

    // 移动赋值
    c = std::move(b);

    std::cout << "c.name: " << c.name << '\n';

    // 取消下面两行的注释，分别编译验证
    // Student d = c;
    // c = c;

    return 0;
}