#include "includes/Animal.hpp"

Animal::Animal()
{
    std::cout << WHITE << "Animal " << RESET << "default constructor called" << std::endl;
}

Animal::Animal(std::string type)
    :   _type(type)
{
    std::cout << WHITE << "Animal " << RESET 
    << "type constructor called for " << _type << std::endl;
}

//Copy constructor
Animal::Animal(const Animal& copy)
    :   _type(copy._type)
{
    std::cout << WHITE << "Animal " << RESET << "copy constructor called" << std::endl;
    return ;
}

//Copy asigment operator overload
Animal& Animal::operator= (const Animal& copy)
{
    if(this == &copy)
        return *this;
    _type = copy._type;
    std::cout << WHITE << "Animal " << RESET 
    << "copy assignment operator overload" << std::endl;
    return (*this);
}

void Animal::makeSound() const
{
    std::srand((unsigned int)(std::time(0))); //generates random number that changes according with time
    std::string sound[5] = {"Muuu", "Beeee", "Wooof", "Quack", "Meow"};
    int i = std::rand() % 5; //random index entre 0 e 5
    std::cout << "Animal makes random sound: " << WHITE 
    << sound[i] << RESET << std::endl;
}

void    Animal::display() const
{
    std::cout << std::endl;
    std::cout << CYAN << " DISPLAY ANIMAL" << RESET << std::endl;
    if(!_type.empty())
        std::cout << "Hello, I'm a " << _type << "!" << std::endl;
    else
        std::cout << "Who am I? *" << WHITE 
        << "Having an existencial crises" << RESET << "*" << std::endl;
}

Animal::~Animal()
{
    std::cout << WHITE << "Animal " << RESET << "destructor called" << std::endl;
}