#pragma once 
#include<string>
#include<iostream>
#include<memory>

struct Student
{
    int age;
    std::string name;
    double score;

    ~Student()
    {
        std::cout << "Student destroyed\n";
    }
};

void printStudent(std::shared_ptr<Student> student);
