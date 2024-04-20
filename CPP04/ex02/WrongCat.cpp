#include "includes/WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("WrongCat")
{
    std::cout << BOLD_GREEN << "WrongCat " << RESET 
    << "default constructor called" << std::endl;
}

WrongCat::WrongCat(std::string type)
    :   WrongAnimal(type)
{
    std::cout << "WrongCat name constructor called" << std::endl;
}

//Copy constructor
WrongCat::WrongCat(const WrongCat& copy)
    :   WrongAnimal(copy)
{
    std::cout << BOLD_GREEN << "WrongCat " << RESET 
    << "copy constructor called" << std::endl;
    return ;
}

//Copy asigment operator overload
WrongCat& WrongCat::operator= (const WrongCat& copy)
{
    if(this == &copy)
        return *this;
    _type = copy._type;
    std::cout << BOLD_GREEN << "WrongCat " << RESET 
    << "copy assignment operator overload" << std::endl;
    return (*this);
}

void WrongCat::makeSound() const
{
    std::cout << "WrongCat makes WrongCat sound: " << BOLD_GREEN 
    << "Meow"<< RESET << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << BOLD_GREEN << "WrongCat " << RESET 
    << "destructor called" << std::endl;
}