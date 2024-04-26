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
        AMateria    *_inventory[4];
};

#endif // MATERIASOURCE_H
