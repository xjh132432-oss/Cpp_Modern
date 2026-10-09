#pragma once
#include<iostream>
#include<string>

struct Student
{   
    std::string name;
    int age;
    double score;

     ~Student()
    {
        std::cout << "Student destroyed\n";
    }
};

void testUniqueOwnership();

void testRawPointer();
