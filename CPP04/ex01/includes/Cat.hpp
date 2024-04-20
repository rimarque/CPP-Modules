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
        //Copy constructor
        Cat(const Cat& copy);
        //Copy assignment constructor
        Cat& operator= (const Cat& copy);
        //Myfuncions
        void    makeSound() const;
        void    display() const;
        void    setBrain(std::string ideas) const;
        ~Cat();
};

#endif