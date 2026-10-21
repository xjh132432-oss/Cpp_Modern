#include "shared_ptr.h"

int main()
{   
    std::weak_ptr<Student> weak;

    {
        auto Student1 =std::make_shared<Student>();

        Student1->name="Alice";

        weak=Student1;

        std::cout<<Student1.use_count()<<'\n';

        auto student2=weak.lock();

        if(student2) std::cout<<student2->name<<'\n';
    }
    

    if(weak.expired()) std::cout<<"YES"<<'\n';
    else std::cout<<"NO"<<'\n';

    auto student3=weak.lock();

    if(!student3) std::cout<<"Object expired!"<<'\n';
    
    return 0;
}