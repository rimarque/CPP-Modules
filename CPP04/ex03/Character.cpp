#include "includes/Character.hpp"

Character::Character() {
    for(int i = 0; i < 4;i++){
        _inventory[i] = NULL;
    }
    std::cout << WHITE << "Character" << RESET 
    << " default constructor called" << std::endl;
}

Character::Character(std::string name): _name(name) {
    for(int i = 0; i < 4;i++){
        _inventory[i] = NULL;
    }
    std::cout << WHITE << "Character" << RESET 
    << " name constructor called" << std::endl;
}

// Copy constructor
Character::Character(const Character& copy) {
    for(int i = 0; i < 4;i++){
        if(copy._inventory[i]->getType().compare("cure"))  
            _inventory[i] = new Cure(*copy._inventory[i]);
        else
            _inventory[i] = new Ice(*copy._inventory[i]);
    }
    std::cout << WHITE << "Character" << RESET 
    << " copy constructor called" << std::endl;
}

// Copy assignment operator overload
Character& Character::operator= (const Character& copy) {
    // Self-assignment check
    if (this == &copy)
        return *this;
    for(int i = 0; i < 4;i++){
        if(copy._inventory[i]->getType().compare("cure"))  
            _inventory[i] = new Cure(*copy._inventory[i]);
        else
            _inventory[i] = new Ice(*copy._inventory[i]);
    }
    std::cout << WHITE << "Character" << RESET 
    << " copy assignment operator overload" << std::endl;
    return *this;
}

std::string const & Character::getName() const {
    return(_name);
}

void Character::equip(AMateria* m)
{
    int i = 0;
    while(_inventory[i] == NULL)
        i++;
    if(i > 3)
        return ;
    for(int i = 0; i < 4;i++){
        if(_inventory[i]->getType().compare("cure"))  
            _inventory[i] = new Cure(*m);
        else
            _inventory[i] = new Ice(*m);
    }
}

void Character::unequip(int idx){
    if (idx < 0 || idx > 3)
        return ;
    this->_inventory[idx]->setType("This Materia was left on the flor"); 
}

void use(int idx, ICharacter& target);

Character::~Character() {
    std::cout << WHITE << "Character" << RESET 
    << " destructor called" << std::endl;
}
