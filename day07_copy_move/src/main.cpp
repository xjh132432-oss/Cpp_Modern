#include "student.h"

int main()
{
    std::cout << "--- Create a ---\n";
    Student a;
    a.name = "Alice";

    std::cout << "--- Copy construct b ---\n";
    Student b = a;

    std::cout << "--- Move construct c ---\n";
    Student c = std::move(a);

    std::cout << "--- Create d ---\n";
    Student d;
    d.name = "David";

    std::cout << "--- Copy assign d = b ---\n";
    d = b;

    std::cout << "--- Move assign d = std::move(b) ---\n";
    d = std::move(b);

    std::cout << "--- Print names ---\n";
    std::cout << "a: " << a.name << '\n';
    std::cout << "b: " << b.name << '\n';
    std::cout << "c: " << c.name << '\n';
    std::cout << "d: " << d.name << '\n';

    std::cout << "--- End main ---\n";
    return 0;
}