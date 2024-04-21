#include "includes/Animal.hpp"

Animal::Animal()
{
    std::cout << BOLD_WHITE << "Animal " << RESET << "default constructor called" << std::endl;
}

Animal::Animal(std::string type)
    :   _type(type)
{
    std::cout << BOLD_WHITE << "Animal " << RESET 
    << "type constructor called for " << _type << std::endl;
}

//Copy constructor (deep copy)
Animal::Animal(const Animal& copy)
    :   _type(copy._type)
{
    std::cout << BOLD_WHITE << "Animal " << RESET << "copy constructor called" << std::endl;
    return ;
}

//Copy asigment operator overload (deep copy)
Animal& Animal::operator= (const Animal& copy)
{
    if(this == &copy)
        return *this;
    _type = copy._type;
    std::cout << BOLD_WHITE << "Animal " << RESET 
    << "copy assignment operator overload" << std::endl;
    return (*this);
}

std::string     Animal::getType() const
{
    std::cout << BOLD_WHITE << "Calling getType: ";
    return(_type);
}

void Animal::randomSound(std::string *sound) const
{
    //Generating random number that changes according to the current time
    std::srand((unsigned int)(std::time(0)));
    //Computing a random index between 0 e 5
    int i = std::rand() % 5;
    std::cout << "Animal makes random sound: " << BOLD_WHITE 
    << sound[i] << RESET << std::endl;
}

void Animal::animalSound(std::string *sound) const
{   
    std::string animal[5] = {"Cow", "Sheep", "Dog", "Duck", "Cat"};
    for(int i = 0; i < (int)ARRAY_SIZE(animal); i++){
        if(!animal[i].compare(_type))
        {
            std::cout << "Animal makes " << _type << " sound: " << BOLD_WHITE 
            << sound[i] << RESET << std::endl;
            return ;
        }
    }
    std::cout << "There is no sound for " << _type 
    << " in our database!" << std::endl;
}

void Animal::makeSound() const
{
    std::string sound[5] = {"Muuu", "Beeee", "Wooof", "Quack", "Meoww"};
    if(_type.empty())
        this->randomSound(sound);
    else
        this->animalSound(sound);
}

void    Animal::display() const
{
    std::cout << BOLD_CYAN << "Display animal: " << RESET;
    if(!_type.empty())
        std::cout << "Hello, I'm a " << _type << "!" << std::endl;
    else
        std::cout << "Who am I? *" << BOLD_WHITE 
        << "Having an existencial crises" << RESET << "*" << std::endl;
}

bool    Animal::operator== (const std::string& compare) const
{
    if(_type.compare(compare) == 0)
        return(true);
    return(false);
}

Animal::~Animal()
{
    std::cout << BOLD_WHITE << "Animal " << RESET << "destructor called" << std::endl;
}