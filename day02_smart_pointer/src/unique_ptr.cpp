#include <iostream>
#include <memory>
#include "unique_ptr.h"

void createStudent()
{
    std::unique_ptr<Student> student =
        std::make_unique<Student>("Alice", 20, 90.5);

    std::cout << student->name << '\n';
}