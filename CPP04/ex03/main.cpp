#include "includes/Cure.hpp"

int main()
{
    //AMateria a;
    Cure    b;
    Ice     c;

    std::cout << GREEN << "-------Get type of Cure: " 
    << RESET << b.getType() << std::endl;
    std::cout << CYAN << "-------Get type of Ice: " 
    << RESET << c.getType() << std::endl;

    Cure *d = b.clone();
    Ice *e = c.clone();

    std::cout << GREEN << "-------Get type of Cure Clone: " 
    << RESET << d->getType() << std::endl;
    std::cout << CYAN << "-------Get type of Ice Clone: " 
    << RESET << e->getType() << std::endl;

    delete d;
    delete e;
}

/* int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;
    return 0;
} */
