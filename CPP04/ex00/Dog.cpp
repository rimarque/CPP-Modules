#include "includes/Dog.hpp"

Dog::Dog(): Animal("Dog")
{
    std::cout << BOLD_PURPLE << "Dog " << RESET 
    << "default constructor called" << std::endl;
}

Dog::Dog(std::string type)
    :   Animal(type)
{
    std::cout << BOLD_PURPLE << "Dog " << RESET 
    << "name constructor called" << std::endl;
}

//Copy constructor
Dog::Dog(const Dog& copy)
    :   Animal(copy)
{
    std::cout << BOLD_PURPLE << "Dog " << RESET 
    << "copy constructor called" << std::endl;
    return ;
}

//Copy asigment operator overload
Dog& Dog::operator= (const Dog& copy)
{
    if(this == &copy)
        return *this;
    _type = copy._type;
    std::cout << BOLD_PURPLE << "Dog " << RESET 
    << "copy assignment operator overload" << std::endl;
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "Dog makes Dog sound: " << BOLD_PURPLE 
    << "Woof"<< RESET << std::endl;
}

Dog::~Dog()
{
    std::cout << BOLD_PURPLE << "Dog " << RESET 
    << "destructor called" << std::endl;
}