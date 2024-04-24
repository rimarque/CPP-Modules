#ifndef ICHARACTER_H
# define ICHARACTER_H

# include "Cure.hpp"

class ICharacter {
    public:
        virtual ~ICharacter() {} // Destructor
        virtual std::string const & getName() const = 0;
        virtual void equip(AMateria* m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter& target) = 0;
    protected:
        std::string _name;
};

#endif // ICHARACTER_H