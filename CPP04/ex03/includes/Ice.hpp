#ifndef ICE_H
# define ICE_H

# include "AMateria.hpp"

class Ice: public AMateria
{
    public:
        Ice(); // Constructor
        Ice(const Ice& copy);//Copy constructor
        //Ice(const AMateria& copy);
        Ice& operator= (const Ice& copy); //Copy assignment constructor
        Ice* clone() const; //Returns a clone of the class
        void use(ICharacter& target);
        ~Ice(); // Destructor
};

#endif // ICE_H
