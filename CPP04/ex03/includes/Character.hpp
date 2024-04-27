#ifndef CHARACTER_H
# define CHARACTER_H

# include "ICharacter.hpp"

class Character: public ICharacter
{
    public:
        Character(); // Constructor
        Character(std::string name); //Name constructor
        Character(const Character& copy);//Copy constructor
        Character& operator= (const Character& copy); //Copy assignment constructor
        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
        ~Character(); // Destructor

    private:
        static const int  _maxInv = 4;
        static const int  _maxDropedInv = 1000;
        AMateria*   _inventory[_maxInv];
        AMateria*   _dropedInventory[_maxDropedInv];
        std::string _name;
};

#endif // CHARACTER_H
