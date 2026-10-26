#pragma once 
#include<iostream>
#include<string>
#include<utility>

class Student{

    public:
        std::string name;

        Student(){
            std::cout<<"Default Constructor"<<std::endl;
        }
        ~Student(){
            std::cout << "Destructor: " << name << '\n';
        }

        Student(const Student& other){
            std::cout<<"Copy Constructor"<<std::endl;
            this->name=other.name;
        }
        Student operator=(const Student& other)
        {   
            std::cout<<"Copy Assignment"<<std::endl;

            if(this==&other) return *this;

            this->name=other.name;

            return *this;
        }

        Student(Student&& other) noexcept
        {
            std::cout<<"Move Copy Constructor"<<std::endl;

            this->name=std::move(other.name);
        }

        Student operator=(Student&& other) noexcept
        {
            std::cout<<"Move Copy Assignment"<<std::endl;
            
            if(this==&other) return *this;

            this->name=std::move(other.name);

            return *this;
        }
};