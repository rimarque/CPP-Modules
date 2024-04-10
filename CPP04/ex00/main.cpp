#include "includes/Dog.hpp"

int main()
{
    Animal  a;
    Cat     b;
    Dog     c;

    a.display();
    a.makeSound();
    b.display();
    b.makeSound();
    c.display();
    c.makeSound();
    std::cout << std::endl;
    return 0;
}