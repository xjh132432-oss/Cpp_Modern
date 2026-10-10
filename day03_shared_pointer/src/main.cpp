#include <iostream>
#include <memory>
#include "shared_ptr.h"

int main()
{
    auto student1 = std::make_shared<Student>();
    student1->name = "Alice";

    auto student2 = std::move(student1);

    std::cout << student1.use_count() << '\n';
    std::cout << student2.use_count() << '\n';

    
    
    // printStudent(student1);

    // std::cout<<student1.use_count()<<'\n';

    // {
    //     auto student2=student1;

    //     student2->name = "Bob";

    //     std::cout << student1->name << '\n';

    //     std::cout<<student1.use_count()<<'\n';

    // }

    // std::cout<<student1.use_count()<<'\n';

    std::cout << "main ending\n";
    return 0;
}