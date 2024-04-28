#include "includes/MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for(int i = 0; i < _maxInv;i++){
        _inventory[i] = NULL;
    }
    std::cout << BOLD_YELLOW << "MateriaSource" << RESET 
    << " default constructor called" << std::endl;
}

// Copy constructor
MateriaSource::MateriaSource(const MateriaSource& copy) {
    for(int i = 0; i < _maxInv;i++){
        if(copy._inventory[i])
            _inventory[i] = copy._inventory[i]->clone();
        else
            _inventory[i] = NULL;
    }
    std::cout << BOLD_YELLOW << "MateriaSource" << RESET 
    << " copy constructor called" << std::endl;
}

// Copy assignment operator overload
MateriaSource& MateriaSource::operator= (const MateriaSource& copy) {
    // Self-assignment check
    if (this == &copy)
        return *this;
    for(int i = 0; i < _maxInv; i++){
            if (_inventory[i])
                delete _inventory[i];
            if(copy._inventory[i])
                _inventory[i] = copy._inventory[i]->clone();
            else
                _inventory[i] = NULL;
    }
    std::cout << BOLD_YELLOW << "MateriaSource" << RESET 
    << " copy assignment operator overload" << std::endl;
    return *this;
}

void            MateriaSource::learnMateria(AMateria* m){
    std::cout << "Calling learnMateria... ";
    int i = 0;
    if(m == NULL){
        std::cout << "Materia is NULL, nothing to do" << std::endl;
        return ;
    }
    //Se a AMateria ja estiver preenchida vai para proximo idx
    while(i < _maxInv &&_inventory[i]){
        i++;
    }
    //Se i = _maxInv, o inventorio esta cheio
    if(i == _maxInv)
    {
        std::cout << "MateriaSource inventory is full, nothing to do" << std::endl;
        delete m;
        return ;
    }
    _inventory[i] = m;
    std::cout << "MateriaSource learned the materia " << m->getType()
    << " and stored it at index " << i << std::endl;
}

AMateria*       MateriaSource::createMateria(std::string const & type){
    std::cout << "Calling createMateria.. ";
    for(int i = 0; i < _maxInv && _inventory[i]; i++)
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
    for(int i = 0; i < _maxInv && _inventory[i];i++)
            delete _inventory[i];
    std::cout << BOLD_YELLOW << "MateriaSource" << RESET 
    << " destructor called" << std::endl;
}
