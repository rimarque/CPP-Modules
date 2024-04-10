#ifndef CAT_H
# define CAT_H

# include "Animal.hpp"

class Cat: public Animal
{
    public:
        //Default constructor
        Cat();
        //Constructor that inicialized _name
        Cat(std::string name);
        //Copy constructor
        Cat(const Cat& copy);
        //Copy assignment constructor
        Cat& operator= (const Cat& copy);
        //Myfuncions
        void    makeSound() const;
        ~Cat();
        
};

#endif