#include "student.h"
#include<vector>

int main()
{
    std::vector<Student> students;

    students.reserve(10);

    students.emplace_back("alice",90);

    std::cout<<"size:"<<students.size()
            <<" cap:"<<students.capacity()<<'\n';

    {
        Student B;
        B.name="Bob";
        B.score=85;

        students.push_back(B);
    }

    std::cout<<"size:"<<students.size()
            <<" cap:"<<students.capacity()<<'\n';

    std::cout<<"-------------------Move---------------"<<'\n';
    
    Student cha;
    cha.name="Charlie";
    cha.score=95;
    
    students.push_back(std::move(cha));

    std::cout<<"size:"<<students.size()
            <<" cap:"<<students.capacity()<<'\n';

    std::cout<<"----------------student-------------------"<<'\n';

    int max=0,sum=0;
    std::string name;

    for(std::vector<Student>::iterator it=students.begin();
        it!=students.end();it++)
        {   
            std::cout<<(*it).name<<" "<<(*it).score<<'\n';

            if((*it).score>max) 
            {
                name=(*it).name;
                max=(*it).score;
            }
            sum+=(*it).score;
        }

        std::cout<<"-----------analysis----------------------"<<'\n';
        std::cout<<"avergae:"<<double(sum)/double(students.size())<<'\n'
                <<"max:"<<max<<" "<<name<<'\n';

    return 0;
}