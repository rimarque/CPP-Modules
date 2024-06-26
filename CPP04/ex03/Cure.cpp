#include "includes/Cure.hpp"
#include "includes/ICharacter.hpp"

Cure::Cure(): AMateria("cure") {
    std::cout << BOLD_GREEN << "Cure" << RESET 
    << " default constructor called" << std::endl;
}

// Copy constructor
Cure::Cure(const Cure& copy): AMateria(copy) {
    std::cout << BOLD_GREEN << "Cure" << RESET 
    << " copy constructor called" << std::endl;
}

/* Cure::Cure(const AMateria& copy): AMateria(copy){
     std::cout << BOLD_GREEN << "Cure-Amateria" << RESET 
    << " copy constructor called" << std::endl;
} */

// Copy assignment operator overload
Cure& Cure::operator= (const Cure& copy){
    // Self-assignment check
    if (this == &copy)
        return *this;
    _type = copy._type;
    std::cout << BOLD_GREEN << "Cure" << RESET 
    << " copy assignment operator overload" << std::endl;
    return *this;
}

//Returns a clone of the class
Cure* Cure::clone() const {
    return(new Cure(*this)); 
}

void Cure::use(ICharacter& target){
    std::cout << BOLD_GREEN << "Cure " << RESET 
    << "heals " << target.getName() << "'s wounds" << std::endl;
}

Cure::~Cure() {
    std::cout << BOLD_GREEN << "Cure" << RESET 
    << " destructor called" << std::endl;
}
