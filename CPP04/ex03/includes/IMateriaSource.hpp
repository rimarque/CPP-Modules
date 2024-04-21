#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H

# include "ICharacter.hpp"

class IMateriaSource {
public:
    virtual ~IMateriaSource() {}
    virtual void learnMateria(AMateria*) = 0;
    virtual AMateria* createMateria(std::string const & type) = 0;

};

#endif // MATERIASOURCE_H
