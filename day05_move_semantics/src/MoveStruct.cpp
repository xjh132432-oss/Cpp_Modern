#include "moveDF.h"

int main()
{
    Student student1;
    student1.name = "Alice";

    std::cout << "--- Move Construction ---\n";
    Student student2 = std::move(student1);

    Student student3;
    student3.name = "Bob";

    std::cout << "--- Move Assignment ---\n";
    student3 = std::move(student2);

    std::cout << "student1: " << student1.name << '\n';
    std::cout << "student2: " << student2.name << '\n';
    std::cout << "student3: " << student3.name << '\n';

    return 0;
}