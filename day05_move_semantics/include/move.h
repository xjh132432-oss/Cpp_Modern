#pragma once
#include<string>
#include<iostream>
#include<memory>
#include<utility>


class Student
{
public:
    std::string name;

    Student() = default;
   
    Student(Student&& other) noexcept
    : name(std::move(other.name))
{
    std::cout << "Move Constructor\n";
}

Student& operator=(Student&& other) noexcept
{
    name = std::move(other.name);
    std::cout << "Move Assignment\n";
    return *this;
}
};