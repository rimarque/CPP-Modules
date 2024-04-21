#include "includes/Character.hpp"

Character::Character() {
    for(int i = 0; i < 4;i++){
        _inventory[i] = NULL;
    }
    std::cout << WHITE << "Character" << RESET 
    << " default constructor called" << std::endl;
}

// Copy constructor
Character::Character(const Character& copy) {
    for(int i = 0; i < 4;i++){
        if(_inventory[i]->getType().compare("cure"))
            *_inventory[i] = new Cure();
    }
    std::cout << WHITE << "Character" << RESET 
    << " copy constructor called" << std::endl;
}

// Copy assignment operator overload
Character& Character::operator= (const Character& copy) {
    // Self-assignment check
    if (this == &copy)
        return *this;
    // Copy stuff
    std::cout << WHITE << "Character" << RESET 
    << " copy assignment operator overload" << std::endl;
    return *this;
}

std::string const & getName() const;
void equip(AMateria* m);
void unequip(int idx);
void use(int idx, ICharacter& target);

Character::~Character() {
    std::cout << WHITE << "Character" << RESET 
    << " destructor called" << std::endl;
}
