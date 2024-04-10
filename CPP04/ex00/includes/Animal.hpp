#ifndef ANIMAL_H
# define ANIMAL_H
# include <iostream>
# include <string.h>
# include <unistd.h>
# include <cstdlib>
# include <ctime>
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define PURPLE "\033[1;35m"
# define YELLOW "\033[1;33m"
# define WHITE 	"\033[1;37m"
# define CYAN "\033[1;36m"
# define RESET "\033[0m"

class Animal 
{
    protected:
        std::string _type;
    public:
        //Default constructor
        Animal();
        //Constructor that inicialized _name
        Animal(std::string name);
        //Copy constructor
        Animal(const Animal& copy);
        //Copy assignment constructor
        Animal& operator= (const Animal& copy);
        //Myfuncions
        virtual void    makeSound() const;
        void    display() const;
        ~Animal();
        
};

#endif