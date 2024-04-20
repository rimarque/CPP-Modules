#ifndef DOG_H
# define DOG_H

# include "Cat.hpp"
# include "Brain.hpp"

class Dog: public Animal
{
    private:
        Brain *_brain;
    public:
        //Default constructor
        Dog();
        //Copy constructor
        Dog(const Dog& copy);
        //Copy assignment constructor
        Dog&    operator= (const Dog& copy);
        //Myfuncions
        void    makeSound() const;
        void    display() const;
        ~Dog();
        
};

#endif