#include "student.h"
int main()
{
    // 1. 创建对象 a，并设置 name 和 age
    Student a;
    a.name="alice";
    a.age=17;
    // // 2. 测试使用 a 拷贝构造对象 b
    Student b=a;
    // // 3. 创建对象 c，再使用 a 对 c 进行拷贝赋值
    // Student c;
    // c=a;
    // // 4. 使用 std::move(a) 构造对象 d
    // Student d=std::move(a);
    // // 5. 输出 b、c、d 的 name
    // std::cout<<"b:"<<b.name<<'\n'
    //         <<"c:"<<c.name<<'\n'
    //         <<"d:"<<d.name<<'\n';

    return 0;
}