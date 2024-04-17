#ifndef CAT_H
# define CAT_H

# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal
{
    private:
        Brain *_brain;
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
        void    display() const;
        ~Cat();
        
};

#endif