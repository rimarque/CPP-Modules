#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H

# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
    public:
        MateriaSource(); // Constructor
        MateriaSource(const MateriaSource& copy);//Copy constructor
        MateriaSource& operator= (const MateriaSource& copy); //Copy assignment constructor
        void            learnMateria(AMateria*);
        AMateria*       createMateria(std::string const & type);
        ~MateriaSource(); // Destructor

    private:
        static const int  _maxInv = 4;
        AMateria    *_inventory[_maxInv];
};

#endif // MATERIASOURCE_H
