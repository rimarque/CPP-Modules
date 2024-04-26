#include "includes/Character.hpp"
#include "includes/Cure.hpp"
#include "includes/MateriaSource.hpp"

//Testing AMateria and derived classes; ICharacter and Character --> use, equip and deep copys
/* int main()
{
    std::cout << GREEN << "-------Creating a pointer to a ICharacter me:" << std::endl;    
    ICharacter* me = new Character("me");
    std::cout << GREEN << "-------Creating a pointer to a ICharacter bob:" << std::endl; 
    ICharacter* bob = new Character("bob");
    std::cout << GREEN << "-------Creating a pointer to AMateria cure:" << std::endl; 
    AMateria    *cure = new Cure;
    std::cout << GREEN << "-------Creating a pointer to AMateria Ice:" << std::endl; 
    AMateria     *ice = new Ice;
    std::cout << std::endl;
    std::cout << YELLOW << "-------Equiping me:" << RESET << std::endl;
    me->equip(cure);
    me->equip(ice);
    std::cout << std::endl;
    std::cout << YELLOW << "-------Using me to target bob:" << RESET << std::endl;
    me->use(0, *bob);
    me->use(1, *bob);
    std::cout << std::endl;
    std::cout << PURPLE << "-------Testing copys:" << std::endl;
    std::cout << std::endl;
    std::cout << GREEN << "-------Creating a Character rita:" << std::endl;
    Character rita("rita");
    std::cout << YELLOW << "-------Equiping rita:" << RESET << std::endl;
    rita.equip(cure);
    rita.equip(ice);
    std::cout << std::endl;
    std::cout << GREEN << "-------Creating a Character copy:" << std::endl;
    Character copy;
    std::cout << YELLOW << "-------Using rita to target rita:" << RESET << std::endl;
    rita.use(0, rita);
    rita.use(1, rita);
    std::cout << YELLOW << "-------Using copy to target copy:" << RESET << std::endl;
    copy.use(0, copy);
    copy.use(1, copy);
    std::cout << std::endl;
    std::cout << GREEN << "-------Assigning rita to copy:" << std::endl;
    copy = rita;
    std::cout << YELLOW << "-------Using copy to target copy:" << RESET << std::endl;
    copy.use(0, copy);
    copy.use(1, copy);
    std::cout << std::endl;
    std::cout << GREEN << "-------Using copy constructor to copy rita to copy1:" << std::endl;
    Character *copy1 = new Character(rita);
    std::cout << YELLOW << "-------Using copy1 to target copy1:" << RESET << std::endl;
    copy1->use(0, *copy1);
    copy1->use(1, *copy1);
    std::cout << std::endl;
    std::cout << RED << "-------Deleting ICharacter bob:" << std::endl; 
    delete bob;
    std::cout << RED << "-------Deleting ICharacter me:" << std::endl; 
    delete me;
    std::cout << RED << "-------Deleting AMateria cure:" << std::endl; 
    delete cure;
    std::cout << RED << "-------Deleting AMateria ice:" << std::endl; 
    delete ice;
    std::cout << RED << "-------Deleting Character copy1:" << std::endl;
    delete copy1;
    return 0;
} */

//Testing Character functions (equip, use, unequip)
/* int main()
{
    std::cout << GREEN << "-------Creating a pointer to a ICharacter me:" << std::endl;    
    ICharacter* me = new Character("me");
    std::cout << GREEN << "-------Creating a pointer to a ICharacter bob:" << std::endl; 
    ICharacter* bob = new Character("bob");
    std::cout << GREEN << "-------Creating a pointer to AMateria cure:" << std::endl; 
    AMateria    *cure = new Cure;
    std::cout << GREEN << "-------Creating a pointer to AMateria Ice:" << std::endl; 
    AMateria     *ice = new Ice;
    std::cout << std::endl;
    std::cout << YELLOW << "-------Using me to target bob:" << RESET << std::endl;
    for(int i = 0; i < 8; i++){
        me->use(i, *bob);
    }
    std::cout << std::endl;
    std::cout << YELLOW << "-------Equiping me:" << RESET << std::endl;
    for(int i = 0; i < 8; i++){
       if(i % 2 == 0)
            me->equip(cure);
        else
            me->equip(ice);
    }
    std::cout << std::endl;
    std::cout << YELLOW << "-------Using me to target bob:" << RESET << std::endl;
    for(int i = 0; i < 8; i++){
        me->use(i, *bob);
    }
    std::cout << std::endl;
    std::cout << YELLOW << "-------Unequiping me:" << RESET << std::endl;
    for(int i = 0; i < 8; i++){
        me->unequip(i);
    }
    std::cout << std::endl;
    std::cout << YELLOW << "-------Using me to target bob:" << RESET << std::endl;
    for(int i = 0; i < 8; i++){
        me->use(i, *bob);
    }
    std::cout << std::endl;
    std::cout << YELLOW << "-------Equiping me:" << RESET << std::endl;
    for(int i = 0; i < 8; i++){
       if(i % 2 == 0)
            me->equip(cure);
        else
            me->equip(ice);
    }
    std::cout << std::endl;
    std::cout << RED << "-------Deleting ICharacter bob:" << std::endl; 
    delete bob;
    std::cout << RED << "-------Deleting ICharacter me:" << std::endl; 
    delete me;
    std::cout << RED << "-------Deleting AMateria cure:" << std::endl; 
    delete cure;
    std::cout << RED << "-------Deleting AMateria ice:" << std::endl; 
    delete ice;
    return 0;
} */

//Subject main
int main()
{
    std::cout << GREEN << "-------Creating a pointer to an IMateriaSource me:" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    std::cout << GREEN << "-------Creating a pointer to an ICharacter me:" << std::endl;
    ICharacter* me = new Character("me");
    AMateria* tmp;
    std::cout << YELLOW << "-------Creating Materia Ice:" << RESET << std::endl;
    tmp = src->createMateria("ice");
    std::cout << YELLOW << "-------Equiping me:" << RESET << std::endl;
    me->equip(tmp);
    std::cout << YELLOW << "-------Creating Materia cure:" << RESET << std::endl;
    tmp = src->createMateria("cure");
    std::cout << YELLOW << "-------Equiping me:" << RESET << std::endl;
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    std::cout << YELLOW << "-------Using me to target bob:" << RESET << std::endl;
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;
    return 0;
}
