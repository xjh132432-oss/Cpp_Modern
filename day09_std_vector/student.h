#pragma once
#include<iostream>
#include<string>
#include<utility>

class Student{

    public:
        std::string name;
        int score=0;

        Student(){
            std::cout<<"defalut Construct"<<'\n';
        }

        Student(std::string name,int score):
        name(name),score(score)
        {
            std::cout<<"Construct"<<std::endl;
        }

        Student(const Student& other)
        : name(other.name),score(other.score){
            std::cout<<"Copy Construct"<<'\n';
        }

        Student(Student&& other) noexcept:
        name(std::move(other.name)),score(std::move(other.score))
        {
            std::cout<<"Move Construct:"<<name<<'\n';
        }

        ~Student()
        {
            std::cout<<"Destructor"<<'\n';
            
        }
    
};