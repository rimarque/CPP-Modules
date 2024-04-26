#include "includes/MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for(int i = 0; i < 4;i++){
        _inventory[i] = NULL;
    }
    std::cout << WHITE << "MateriaSource" << RESET 
    << " default constructor called" << std::endl;
}

// Copy constructor
MateriaSource::MateriaSource(const MateriaSource& copy) {
    for(int i = 0; i < 4;i++){
        if(copy._inventory[i])
            _inventory[i] = copy._inventory[i]->clone();
        else
            _inventory[i] = NULL;
    }
    std::cout << WHITE << "MateriaSource" << RESET 
    << " copy constructor called" << std::endl;
}

// Copy assignment operator overload
MateriaSource& MateriaSource::operator= (const MateriaSource& copy) {
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
    std::cout << WHITE << "MateriaSource" << RESET 
    << " copy assignment operator overload" << std::endl;
    return *this;
}

void            MateriaSource::learnMateria(AMateria* m){
    std::cout << "Calling learnMateria.. ";
    if(m == NULL){
        std::cout << "Materia is NULL, nothing to do" << std::endl;
        return ;
    }
    int i = 0;
    //Se a AMateria ja estiver preenchida vai para proximo idx
    while(_inventory[i] && i < 4)
        i++;
    //Se i = 4, o inventorio esta cheio
    if(i == 4)
    {
        std::cout << "Inventory is full, nothing to do" << std::endl;
        return ;
    }
    _inventory[i] = m;
    std::cout << "Materia Source as learned AMateria " << m->getType()
    << "and store it at index " << i << std::endl;
}

AMateria*       MateriaSource::createMateria(std::string const & type){
    std::cout << "Calling createMateria.. ";
    for(int i = 0; i < 4; i++)
    {
        if(!_inventory[i]->getType().compare(type)){
            std::cout << "AMateria created successfully" << std::endl;
            return(_inventory[i]->clone());
        }
    }
    std::cout << "No such materia has been learned" << std::endl;
    return NULL;
}

MateriaSource::~MateriaSource() {
    for(int i = 0; i < 4;i++){
        if (_inventory[i] != nullptr) {
            delete _inventory[i];
        }
    }
    std::cout << WHITE << "MateriaSource" << RESET 
    << " destructor called" << std::endl;
}
