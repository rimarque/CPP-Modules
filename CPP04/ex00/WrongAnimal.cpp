#include "includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << WHITE << "WrongAnimal " << RESET << "default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
    :   _type(type)
{
    std::cout << WHITE << "WrongAnimal " << RESET 
    << "type constructor called for " << _type << std::endl;
}

//Copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal& copy)
    :   _type(copy._type)
{
    std::cout << WHITE << "WrongAnimal " << RESET << "copy constructor called" << std::endl;
    return ;
}

//Copy asigment operator overload
WrongAnimal& WrongAnimal::operator= (const WrongAnimal& copy)
{
    if(this == &copy)
        return *this;
    _type = copy._type;
    std::cout << WHITE << "WrongAnimal " << RESET 
    << "copy assignment operator overload" << std::endl;
    return (*this);
}

std::string     WrongAnimal::getType() const
{
    return(_type);
}

void WrongAnimal::randomSound(std::string *sound) const
{
    //Generating random number that changes according to the current time
    std::srand((unsigned int)(std::time(0)));
    //Computing a random index between 0 e 5
    int i = std::rand() % 5;
    std::cout << "WrongAnimal makes random sound: " << WHITE 
    << sound[i] << RESET << std::endl;
}

void WrongAnimal::animalSound(std::string *sound) const
{   
    std::string animal[5] = {"Cow", "Sheep", "Dog", "Duck", "Dat"};
    for(int i = 0; i < (int)ARRAY_SIZE(animal); i++){
        if(!animal[i].compare(_type))
        {
            std::cout << "Animal makes " << _type << " sound: " << WHITE 
            << sound[i] << RESET << std::endl;
            return ;
        }
    }
    std::cout << "There is no sound for " << _type 
    << " in our database!" << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::string sound[5] = {"Muuu", "Beeee", "Wooof", "Quack", "Meoww"};
    if(_type.empty())
        this->randomSound(sound);
    else
        this->animalSound(sound);
}

void    WrongAnimal::display() const
{
    std::cout << std::endl;
    std::cout << CYAN << "Display wrong animal: " << RESET; 
    if(!_type.empty())
        std::cout << "Hello, I'm a " << _type << "!" << std::endl;
    else
        std::cout << "Who am I? *" << WHITE 
        << "Having an existencial crises" << RESET << "*" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << WHITE << "Animal " << RESET << "destructor called" << std::endl;
}