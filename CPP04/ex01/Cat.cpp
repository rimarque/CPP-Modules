#include "includes/Cat.hpp"

Cat::Cat(): Animal("Cat")
{
    _brain = new Brain();
    std::cout << BOLD_YELLOW << "Cat " << RESET 
    << "default constructor called" << std::endl;
}

//Copy constructor
Cat::Cat(const Cat& copy)
    :   Animal(copy)
{
    _brain = new Brain(*copy._brain);
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
    if(_brain)
        delete _brain;
    _brain = new Brain(*copy._brain);
    std::cout << BOLD_YELLOW << "Cat " << RESET 
    << "copy assignment operator overload" << std::endl;
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << "Cat makes cat sound: " << BOLD_YELLOW 
    << "Meow"<< RESET << std::endl;
}

void Cat::display() const
{
    std::cout << BOLD_YELLOW << "Display cat: " << RESET;
    _brain->displayIdeas();
    return ;
}

void Cat::setBrain(std::string ideas) const
{
    std::cout << BOLD_YELLOW << "Calling setBrain... " << RESET;
    _brain->setIdeas(ideas);
    return ;
}

Cat::~Cat()
{
    delete _brain;
    std::cout << BOLD_YELLOW << "Cat " << RESET 
    << "destructor called" << std::endl;
}