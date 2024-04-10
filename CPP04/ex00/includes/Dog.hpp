#ifndef DOG_H
# define DOG_H

# include "Cat.hpp"
# include "Animal.hpp"

class Dog: public Animal
{
    public:
        //Default constructor
        Dog();
        //Constructor that inicialized _name
        Dog(std::string name);
        //Copy constructor
        Dog(const Dog& copy);
        //Copy assignment constructor
        Dog& operator= (const Dog& copy);
        //Myfuncions
        void    makeSound() const;
        ~Dog();
        
};

#endif