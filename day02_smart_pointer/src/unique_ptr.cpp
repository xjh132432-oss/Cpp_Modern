#include <iostream>
#include <memory>
#include <iostream>
#include "ptr.h"

void testUniqueOwnership()
{
    std::cout << "1. create student\n";

    auto student = std::make_unique<Student>();
    student->name = "Alice";
    student->age = 20;
    student->score = 90.5;

    std::cout << "2. transfer ownership\n";

    auto student2 = std::move(student);

    std::cout << std::boolalpha;
    std::cout << "student is null: "
              << (student == nullptr) << '\n';

    std::cout << "student2 name: "
              << student2->name << '\n';

    std::cout << "3. function ending\n";
}
