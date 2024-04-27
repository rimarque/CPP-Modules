#include "includes/Ice.hpp"
#include "includes/ICharacter.hpp"

Ice::Ice(): AMateria("ice"){
    std::cout << BOLD_CYAN << "Ice" << RESET 
    << " default constructor called" << std::endl;
}

// Copy constructor
Ice::Ice(const Ice& copy): AMateria(copy){
    std::cout << BOLD_CYAN << "Ice" << RESET 
    << " copy constructor called" << std::endl;
}

/* Ice::Ice(const AMateria& copy): AMateria(copy){
    std::cout << BOLD_CYAN << "Ice-Amateria" << RESET 
    << " copy constructor called" << std::endl;
} */

// Copy assignment operator overload
Ice& Ice::operator= (const Ice& copy) {
    // Self-assignment check
    if (this == &copy)
        return *this;
    // Copy stuff
    std::cout << BOLD_CYAN << "Ice" << RESET 
    << " copy assignment operator overload" << std::endl;
    return *this;
}

//Returns a clone of the class
Ice* Ice::clone() const {
    return new Ice(*this); 
}

void Ice::use(ICharacter& target){
    std::cout << BOLD_CYAN << "Ice" << RESET 
    << " shoots an ice bolt at " << target.getName() << std::endl;
}

Ice::~Ice() {
    std::cout << BOLD_CYAN << "Ice" << RESET 
    << " destructor called" << std::endl;
}
