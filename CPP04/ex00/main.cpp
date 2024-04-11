#include "includes/Dog.hpp"
#include "includes/WrongCat.hpp"

/* int main()
{
    Animal  a;
    Cat     b;
    Dog     c;
    Animal  d("Duck");
    Animal  e("snake");
    WrongAnimal f;
    WrongCat    g;

    a.display();
    a.makeSound();
    b.display();
    b.makeSound();
    c.display();
    c.makeSound();
    d.display();
    d.makeSound();
    e.display();
    e.makeSound();
    f.display();
    f.makeSound();
    g.display();
    g.makeSound();
    std::cout << std::endl;
    return 0;
} */

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    /* std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << meta->getType() << " " << std::endl; */
    i->display();
    j->display();
    meta->display();
    j->makeSound();
    i->makeSound(); //will output the cat sound!
    meta->makeSound();
    return 0;
}