#ifndef CURE_H
# define CURE_H

# include "Ice.hpp"

class Cure: public AMateria
{
public:
    Cure(); // Constructor
    Cure(const Cure& copy);//Copy constructor
    Cure(const AMateria& copy);
    Cure& operator= (const Cure& copy); //Copy assignment constructor
    Cure* clone() const; //Returns a clone of the class
    void use(ICharacter& target);
    ~Cure(); // Destructor
};

#endif // CURE_H
