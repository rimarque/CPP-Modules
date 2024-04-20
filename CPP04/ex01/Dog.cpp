#include "includes/Dog.hpp"

Dog::Dog(): Animal("Dog")
{
    _brain = new Brain();
    std::cout << RED << "Dog " << RESET 
    << "default constructor called" << std::endl;
}

//Copy constructor
Dog::Dog(const Dog& copy)
    :   Animal(copy)
{
    _type = copy._type;
    _brain = new Brain(*copy._brain);
    std::cout << RED << "Dog " << RESET 
    << "copy constructor called" << std::endl;
    return ;
}

//Copy asigment operator overload
Dog& Dog::operator= (const Dog& copy)
{
    if(this == &copy)
        return *this;
    _type = copy._type;
    _brain = new Brain(*copy._brain);
    std::cout << RED << "Dog " << RESET 
    << "copy assignment operator overload" << std::endl;
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "Dog makes Dog sound: " << RED 
    << "Woof"<< RESET << std::endl;
}

void Dog::display() const
{
    std::cout << RED << "Display dog: " << RESET;
    _brain->displayIdeas();
    return ;
}

Dog::~Dog()
{
    delete _brain;
    std::cout << RED << "Dog " << RESET 
    << "destructor called" << std::endl;
}