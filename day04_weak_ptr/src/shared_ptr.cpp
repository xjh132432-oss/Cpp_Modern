#include "shared_ptr.h"

void printStudent(std::shared_ptr<Student> student)
{
    std::cout << student->name << '\n';
    std::cout << student.use_count() << '\n';
}