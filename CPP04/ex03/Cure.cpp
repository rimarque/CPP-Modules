#include "includes/Cure.hpp"

Cure::Cure(): AMateria("cure") {
    std::cout << WHITE << "Cure" << RESET 
    << " default constructor called" << std::endl;
}

// Copy constructor
Cure::Cure(const Cure& copy): AMateria(copy) {
    std::cout << WHITE << "Cure" << RESET 
    << " copy constructor called" << std::endl;
}

/* Cure::Cure(const AMateria& copy): AMateria(copy){
     std::cout << WHITE << "Cure-Amateria" << RESET 
    << " copy constructor called" << std::endl;
} */

// Copy assignment operator overload
Cure& Cure::operator= (const Cure& copy){
    // Self-assignment check
    if (this == &copy)
        return *this;
    _type = copy._type;
    std::cout << WHITE << "Cure" << RESET 
    << " copy assignment operator overload" << std::endl;
    return *this;
}

//Returns a clone of the class
Cure* Cure::clone() const {
    return(new Cure(*this)); 
}

void Cure::use(ICharacter& target){
    std::cout << BOLD_GREEN << "Cure" << RESET 
    << "heals " << target._name << "'s wounds" << std::endl;
}

Cure::~Cure() {
    std::cout << WHITE << "Cure" << RESET 
    << " destructor called" << std::endl;
}
