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
        if(copy._inventory[i])
             _inventory[i] = copy._inventory[i]->clone();
        else
            _inventory[i] = NULL;
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
            if (_inventory[i])
                delete _inventory[i];
            if(copy._inventory[i])
                _inventory[i] = copy._inventory[i]->clone();
            else
                _inventory[i] = NULL;
    }
    std::cout << WHITE << "Character" << RESET 
    << " copy assignment operator overload" << std::endl;
    return *this;
}

std::string const & Character::getName() const {
    return(_name);
}

//nao percebi se tenho de alocar memoria aqui (com o clone)
void Character::equip(AMateria* m)
{
    std::cout << "Calling equip... ";
    if(m == NULL){
        std::cout << "Materia is NULL, nothing to do" << std::endl;
        return ;
    }
    int i = 0;
    while(_inventory[i] == NULL)
        i++;
    if(i > 3)
    {
        std::cout << "Inventory is full, nothing to do" << std::endl;
        return ;
    }
    if (_inventory[i])
        delete _inventory[i];
    _inventory[i] = m;
    std::cout << "Inventory was equiped with " << m->getType() << std::endl;
}

void Character::unequip(int idx){
    if (idx < 0 || idx > 3)
        return ;
    this->_inventory[idx] == NULL;
    std::cout << "Inventory was unequiped at index " << idx << std::endl;
}

void Character::use(int idx, ICharacter& target){
    target._inventory[]
}

Character::~Character() {
    std::cout << WHITE << "Character" << RESET 
    << " destructor called" << std::endl;
}
