#include "move.h"

int main()
{
    auto student1 = std::make_unique<Student>();
    student1->name = "Alice";

    auto student2=std::move(student1);
    
    if(!student1) std::cout<<"1empty"<<'\n';
    if(!student2) std::cout<<"2empty"<<'\n';

    if(student2) std::cout<<student2->name<<'\n';

    return 0;
}