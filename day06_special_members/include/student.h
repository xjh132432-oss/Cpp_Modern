#pragma once 
#include<string>
#include<iostream>
class Student{
    
    public:
        std::string name;

       Student()
       {
            std::cout<<"Default Constructor"<<std::endl;
       }

       ~Student()
        {
            std::cout << "Destructor: " << name << '\n';
        }

        Student(const Student& other)
        {
            std::cout<<"Copy Constructor"<<std::endl;
            this->name=other.name;
        }

        Student& operator=(const Student& other)
        {   
            std::cout<<"Copy Assignment"<<std::endl;

            if(this==&other) return *this;
            
            this->name=other.name;

            return *this;
        }
};