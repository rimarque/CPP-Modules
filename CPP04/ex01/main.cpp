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
    const Animal* cow = new Animal("Cow");
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const WrongAnimal* wMeta = new WrongAnimal("WrongCat");
    const WrongAnimal *w = new WrongCat();

    /* std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << meta->getType() << " " << std::endl; */
    meta->display();
    meta->makeSound();
    cow->display();
    cow->makeSound();
    j->display();
    j->makeSound();
    i->display();
    i->makeSound(); //will output the cat sound!
    wMeta->display();
    wMeta->makeSound();
    w->display();
    w->makeSound();
    std::cout << std::endl;
    delete meta;
    delete cow;
    delete j;
    delete i;
    delete wMeta;
    delete w;
    return 0;
}