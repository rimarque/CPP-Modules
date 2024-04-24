#include "includes/Character.hpp"

Character::Character() {
    for(int i = 0; i < 4;i++){
        _inventory[i] = NULL;
    }
    for(int i = 0; i < 4;i++){
        _dropedInventory[i] = NULL;
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
    //Se a AMateria ja estiver preenchida vai para proximo idx
    while(_inventory[i] 
        && _inventory[i]->getType().compare("Left on the floor")
            && i < 4)
        i++;
    //Se i = 4, o inventorio esta cheio
    if(i == 4)
    {
        std::cout << "Inventory is full, nothing to do" << std::endl;
        return ;
    }
    _inventory[i] = m;
    std::cout << "Inventory was equiped with " << m->getType() << std::endl;
}

void Character::unequip(int idx){
    if (idx < 0 || idx > 3){
        std::cout << "Not a valid index, nothing to do" << std::endl;
        return ;
    }
    _dropedInventory[idx] = _inventory[idx];
    _inventory[idx]->setType("Left on the floor");
    std::cout << "Inventory was unequiped at index " << idx << std::endl;
}

void Character::use(int idx, ICharacter& target){
    if (idx < 0 || idx > 3)
    {
        std::cout << "Not a valid index, nothing to do" << std::endl;
        return ;
    }
    if(_inventory[idx] == NULL){
        std::cout << "Materia is NULL, nothing to do" << std::endl;
        return ;
    }
    _inventory[idx]->use(target);
}

Character::~Character() {
    for(int i = 0; i < 4;i++){
        if (_inventory[i] && _inventory[i]->getType().compare("Left on the floor"))
            delete _inventory[i];
    }
    for(int i = 0; i < 4;i++){
        if (_dropedInventory[i])
            delete _inventory[i];
    }
    std::cout << WHITE << "Character" << RESET 
    << " destructor called" << std::endl;
}
