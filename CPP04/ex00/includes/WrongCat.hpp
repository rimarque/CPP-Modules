#ifndef WRONGCAT_H
# define WRONGCAT_H

# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
    public:
        //Default constructor
        WrongCat();
        //Constructor that inicialized _name
        WrongCat(std::string name);
        //Copy constructor
        WrongCat(const WrongCat& copy);
        //Copy assignment constructor
        WrongCat& operator= (const WrongCat& copy);
        //Myfuncions
        void makeSound() const;
        ~WrongCat();
};

#endif