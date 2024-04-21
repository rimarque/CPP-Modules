#ifndef CHARACTER_H
# define CHARACTER_H

# include "Cure.hpp"

class Character {
public:
    Character(); // Constructor
    Character(const Character& copy);//Copy constructor
    Character& operator= (const Character& copy); //Copy assignment constructor
    std::string const & getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
    ~Character(); // Destructor

private:
    AMateria* _inventory[4];
};

#endif // CHARACTER_H
