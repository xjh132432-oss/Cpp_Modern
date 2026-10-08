#pragma once
#include<string>

struct Student
{   
    std::string name;
    int age;
    double score;

    Student(const std::string& name, int age, double score)
        : name(name), age(age), score(score)
    {
    }
};

void createStudent();
