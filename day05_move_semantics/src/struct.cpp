#include "move.h"

int main()
{
    Student student1;
    student1.name = "Alice";

    // TODO 2：使用 student1 移动构造 student2
    Student student2 = std::move(student1);

    // TODO 3：打印 student2.name
    std::cout<<"2:"<<student2.name<<'\n';
    // TODO 4：打印 student1.name，观察移动后的状态
    std::cout<<"1:"<<student1.name<<'\n';
    
    
    return 0;
}