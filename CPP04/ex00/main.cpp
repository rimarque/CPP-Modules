#include "includes/Dog.hpp"
#include "includes/WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* cow = new Animal("Cow");
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const WrongAnimal* wMeta = new WrongAnimal("WrongCat");
    const WrongAnimal *w = new WrongCat();

/*     std::cout << j->getType() << " " << std::endl;
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