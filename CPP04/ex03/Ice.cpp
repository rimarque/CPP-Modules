#include "includes/Ice.hpp"

Ice::Ice(): AMateria("ice"){
    std::cout << WHITE << "Ice" << RESET 
    << " default constructor called" << std::endl;
}

// Copy constructor
Ice::Ice(const Ice& copy): AMateria(copy){
    std::cout << WHITE << "Ice" << RESET 
    << " copy constructor called" << std::endl;
}

// Copy assignment operator overload
Ice& Ice::operator= (const Ice& copy) {
    // Self-assignment check
    if (this == &copy)
        return *this;
    // Copy stuff
    std::cout << WHITE << "Ice" << RESET 
    << " copy assignment operator overload" << std::endl;
    return *this;
}

//Returns a clone of the class
Ice* Ice::clone() const {
    return(new Ice(*this)); 
}

void Ice::use(ICharacter& target){
    std::cout << BOLD_CYAN << "Ice" << RESET 
    << " shoots an ice bolt at" << target._name << std::endl;
}

Ice::~Ice() {
    std::cout << WHITE << "Ice" << RESET 
    << " destructor called" << std::endl;
}
