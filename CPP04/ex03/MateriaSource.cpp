#include "includes/MateriaSource.hpp"

MateriaSource::MateriaSource() {
    std::cout << WHITE << "MateriaSource" << RESET 
    << " default constructor called" << std::endl;
}

// Copy constructor
MateriaSource::MateriaSource(const MateriaSource& copy) {
    // Copy stuff
    std::cout << WHITE << "MateriaSource" << RESET 
    << " copy constructor called" << std::endl;
}

// Copy assignment operator overload
MateriaSource& MateriaSource::operator= (const MateriaSource& copy) {
    // Self-assignment check
    if (this == &copy)
        return *this;
    // Copy stuff
    std::cout << WHITE << "MateriaSource" << RESET 
    << " copy assignment operator overload" << std::endl;
    return *this;
}

MateriaSource::~MateriaSource() {
    std::cout << WHITE << "MateriaSource" << RESET 
    << " destructor called" << std::endl;
}
