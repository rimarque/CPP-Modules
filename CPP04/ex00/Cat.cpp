#include "includes/Cat.hpp"

Cat::Cat(): Animal("Cat")
{
    std::cout << BOLD_YELLOW << "Cat " << RESET 
    << "default constructor called" << std::endl;
}

Cat::Cat(std::string type)
    :   Animal(type)
{
    std::cout << "Cat name constructor called" << std::endl;
}

//Copy constructor
Cat::Cat(const Cat& copy)
    :   Animal(copy)
{
    std::cout << BOLD_YELLOW << "Cat " << RESET 
    << "copy constructor called" << std::endl;
    return ;
}

//Copy asigment operator overload
Cat& Cat::operator= (const Cat& copy)
{
    if(this == &copy)
        return *this;
    _type = copy._type;
    std::cout << BOLD_YELLOW << "Cat " << RESET 
    << "copy assignment operator overload" << std::endl;
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << "Cat makes cat sound: " << BOLD_YELLOW 
    << "Meow"<< RESET << std::endl;
}

Cat::~Cat()
{
    std::cout << BOLD_YELLOW << "Cat " << RESET 
    << "destructor called" << std::endl;
}