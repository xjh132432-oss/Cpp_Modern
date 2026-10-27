#include <iostream>
#include <string>
#include <utility>

class Student {
public:
    std::string name;
    int age = 0;

    Student()=default;

    Student& operator=(const Student&) =delete;
    Student(const Student&) =delete;

    Student(Student&&)=default;
    Student& operator=(Student&&) =default;
};

