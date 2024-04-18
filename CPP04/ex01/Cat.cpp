#include "includes/Cat.hpp"

Cat::Cat(): Animal("Cat")
{
    _brain = new Brain();
    std::cout << GREEN << "Cat " << RESET 
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
    _type = copy._type;
    _brain = new Brain(*copy._brain);
    std::cout << GREEN << "Cat " << RESET 
    << "copy constructor called" << std::endl;
    return ;
}

//Copy asigment operator overload
Cat& Cat::operator= (const Cat& copy)
{
    if(this == &copy)
        return *this;
    _type = copy._type;
    _brain = new Brain(*copy._brain);
    std::cout << GREEN << "Cat " << RESET 
    << "copy assignment operator overload" << std::endl;
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << "Cat makes cat sound: " << GREEN 
    << "Meow"<< RESET << std::endl;
}

void Cat::display() const
{
    std::cout << GREEN << "Display cat: " << RESET;
    _brain->displayIdeas();
    return ;
}

Cat::~Cat()
{
    delete _brain;
    std::cout << GREEN << "Cat " << RESET 
    << "destructor called" << std::endl;
}