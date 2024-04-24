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
        AMateria*   _inventory[4];
        AMateria*   _dropedInventory[4];
        std::string _name;
};

#endif // CHARACTER_H
