#pragma once
#include<iostream>
#include<string>

struct Student
{
    int age;
    double score;
    std::string name;
};

void printStudent(const Student& student);