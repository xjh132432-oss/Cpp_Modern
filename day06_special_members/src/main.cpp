#include "student.h"

int main()
{
    std::cout << "--- Create a ---\n";
    Student a;
    a.name = "Alice";

    std::cout << "--- Copy construct b ---\n";
    Student b = a;

    std::cout << "--- Create c ---\n";
    Student c;
    c.name = "Bob";

    std::cout << "--- Copy assign c = a ---\n";
    c = a;

    std::cout << "--- Print names ---\n";
    std::cout << a.name << '\n';
    std::cout << b.name << '\n';
    std::cout << c.name << '\n';

    b.name="Charlie";

    std::cout << "--- End main ---\n";
    return 0;
}