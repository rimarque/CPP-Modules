#include "includes/ICharacter.hpp"

ICharacter::ICharacter() {
    std::cout << WHITE << "ICharacter" << RESET 
    << " default constructor called" << std::endl;
}

// Copy constructor
ICharacter::ICharacter(const ICharacter& copy) {
    // Copy stuff
    std::cout << WHITE << "ICharacter" << RESET 
    << " copy constructor called" << std::endl;
}

// Copy assignment operator overload
ICharacter& ICharacter::operator= (const ICharacter& copy) {
    // Self-assignment check
    if (this == &copy)
        return *this;
    // Copy stuff
    std::cout << WHITE << "ICharacter" << RESET 
    << " copy assignment operator overload" << std::endl;
    return *this;
}

ICharacter::~ICharacter() {
    std::cout << WHITE << "ICharacter" << RESET 
    << " destructor called" << std::endl;
}
