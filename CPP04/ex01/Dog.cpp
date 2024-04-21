#include "includes/Dog.hpp"

Dog::Dog(): Animal("Dog")
{
    _brain = new Brain();
    std::cout << BOLD_PURPLE << "Dog " << RESET 
    << "default constructor called" << std::endl;
}

//Copy constructor
Dog::Dog(const Dog& copy)
    :   Animal(copy)
{
    _brain = new Brain(*copy._brain);
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
    _brain = new Brain(*copy._brain);
    std::cout << BOLD_PURPLE << "Dog " << RESET 
    << "copy assignment operator overload" << std::endl;
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "Dog makes Dog sound: " << BOLD_PURPLE 
    << "Woof"<< RESET << std::endl;
}

void Dog::display() const
{
    std::cout << BOLD_PURPLE << "Display dog: " << RESET;
    _brain->displayIdeas();
    return ;
}

void Dog::setBrain(std::string ideas) const
{
    std::cout << BOLD_PURPLE << "Calling setBrain... " << RESET;
    _brain->setIdeas(ideas);
    return ;
}

Dog::~Dog()
{
    delete _brain;
    std::cout << BOLD_PURPLE << "Dog " << RESET 
    << "destructor called" << std::endl;
}