#include "includes/AMateria.hpp"

AMateria::AMateria() {
    std::cout << WHITE << "AMateria" << RESET 
    << " default constructor called" << std::endl;
}

//Constructor that takes a const reference to type
AMateria::AMateria(std::string const & type): _type(type) { 
    std::cout << WHITE << "AMateria" << RESET 
    << " copy constructor called" << std::endl;
}

// Copy constructor
AMateria::AMateria(const AMateria& copy) {
    _type = copy._type;
    std::cout << WHITE << "AMateria" << RESET 
    << " copy constructor called" << std::endl;
}

// Copy assignment operator overload
AMateria& AMateria::operator= (const AMateria& copy) {
    // Self-assignment check
    if (this == &copy)
        return *this;
    _type = copy._type;
    std::cout << WHITE << "AMateria" << RESET 
    << " copy assignment operator overload" << std::endl;
    return *this;
}

std::string const & AMateria::getType() const {
    return(_type);
}

void AMateria::setType(std::string const &type) {
    _type = type;
}

void AMateria::use(ICharacter& target){
    std::cout << WHITE << "AMateria" << RESET 
    << " use called for " << target << std::endl;
}

AMateria::~AMateria() {
    std::cout << WHITE << "AMateria" << RESET 
    << " destructor called" << std::endl;
}
