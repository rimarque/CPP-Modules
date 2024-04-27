#include "includes/Character.hpp"
#include "includes/Cure.hpp"
#include "includes/MateriaSource.hpp"

//Error handling - Materia Source: works!
/* int main()
{
    std::cout << PURPLE << "-------Testing some MateriaSource error handling:" << RESET << std::endl;
    std::cout << GREEN << "-------Creating a pointer to an IMateriaSource src:" << std::endl;
    IMateriaSource *src = new MateriaSource();
    std::cout << GREEN << "-------Creating a pointer to an ICharacter me:" << std::endl;
    ICharacter* me = new Character("me");
    AMateria* tmp;
    std::cout << GREEN << "-------Creating a pointer to a ICharacter bob:" << std::endl;
    ICharacter* bob = new Character("bob");
    std::cout << YELLOW << "-------Learning creating materias and equiping me:" << RESET << std::endl;
    for(int i = 0; i < 8; i++){
       if(i % 2 == 0){
            src->learnMateria(new Ice());
            tmp = src->createMateria("");
            me->equip(tmp);
       }
        else{
            src->learnMateria(NULL);
            tmp = src->createMateria("cure");
            me->equip(tmp);
        }
    }
    std::cout << std::endl;
    std::cout << YELLOW << "-------Using me to target bob:" << RESET << std::endl;
    for(int i = 0; i < 8; i++){
        me->use(i, *bob);
    }
    std::cout << RED << "-------Deleting ICharacter bob:" << std::endl; 
    delete bob;
    std::cout << RED << "-------Deleting ICharacter me:" << std::endl; 
    delete me;
    std::cout << RED << "-------Deleting IMateriaSource src:" << std::endl; 
    delete src;
    return 0;
} */

//Testing deep copys: works!
/* int main()
{
    std::cout << GREEN << "-------Creating a MateriaSource src:" << std::endl;
    MateriaSource src;
    std::cout << YELLOW << "-------Src is learning Materias:" << std::endl;
    src.learnMateria(new Ice());
    src.learnMateria(new Cure());
    std::cout << PURPLE << "-------Testing MateriaSource copys:" << std::endl;
    std::cout << GREEN << "-------Creating MateriaSource copy a with assigment op:" << std::endl;
    MateriaSource a;
    a = src;
    std::cout << GREEN << "-------Creating MateriaSource copy b with copy constructor:" << std::endl;
    MateriaSource b(src);
    std::cout << std::endl;
    std::cout << GREEN << "-------Creating a Character rita:" << std::endl;
    Character rita("rita");
    std::cout << YELLOW << "-------Creating materia cure using MateriaSource a" << RESET << std::endl;
    AMateria *tmp = a.createMateria("cure");
    std::cout << YELLOW << "-------Equiping rita with cure:" << RESET << std::endl;
    rita.equip(tmp);
    std::cout << YELLOW << "-------Creating materia ice using MateriaSource b" << RESET << std::endl;
    tmp = b.createMateria("ice");
    std::cout << YELLOW << "-------Equiping rita with ice:" << RESET << std::endl;
    rita.equip(tmp);
    std::cout << std::endl;
    std::cout << PURPLE << "-------Testing Character copys:" << std::endl;
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
    delete copy1;
    return 0;
} */

//Testing classes and their methods: works!
/* int main()
{
    std::cout << GREEN << "-------Creating a pointer to an IMateriaSource src:" << std::endl;
    IMateriaSource* src = new MateriaSource();
    std::cout << GREEN << "-------Creating a pointer to an ICharacter me:" << std::endl;
    ICharacter* me = new Character("me");
    AMateria* tmp;
    std::cout << GREEN << "-------Creating a pointer to a ICharacter bob:" << std::endl;
    ICharacter* bob = new Character("bob");
    std::cout << PURPLE << "-------Testing empty inventory:" << RESET << std::endl;
    std::cout << YELLOW << "-------Using me to target bob:" << RESET << std::endl;
    for(int i = 0; i < 8; i++){
        me->use(i, *bob);
    }
    std::cout << std::endl;
    std::cout << PURPLE << "-------Testing Equiping and Unequiping Materias:" << RESET << std::endl;
    for(int j = 0; j < 8; j++){
        std::cout << YELLOW << "-------Learning, creating materias and equiping me:" << RESET << std::endl;
        for(int i = 0; i < 8; i++){
        if(i % 2 == 0){
                src->learnMateria(new Cure());
                tmp = src->createMateria("cure");
                me->equip(tmp);
        }
            else{
                src->learnMateria(new Ice());
                tmp = src->createMateria("ice");
                me->equip(tmp);
            }
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
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << RED << "-------Deleting ICharacter bob:" << std::endl; 
    delete bob;
    std::cout << RED << "-------Deleting ICharacter me:" << std::endl; 
    delete me;
    std::cout << RED << "-------Deleting IMateriaSource src:" << std::endl; 
    delete src;
    return 0;
} */

//Subject main
int main()
{
    std::cout << GREEN << "-------Creating a pointer to an IMateriaSource src:" << std::endl;
    IMateriaSource* src = new MateriaSource();
    std::cout << YELLOW << "-------Src is learning Materias:" << std::endl;
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
    std::cout << RED << "-------Deleting ICharacter bob:" << std::endl; 
    delete bob;
    std::cout << RED << "-------Deleting ICharacter me:" << std::endl; 
    delete me;
    std::cout << RED << "-------Deleting IMateriaSource src:" << std::endl; 
    delete src;
    return 0;
}