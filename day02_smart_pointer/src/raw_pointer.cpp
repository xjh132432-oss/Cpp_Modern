#include "ptr.h"

void testRawPointer()
{
    Student* student=new Student;

    student->age=20;
    student->name="Alice";
    student->score=90.5;

    std::cout<<student->name<<'\n';
}