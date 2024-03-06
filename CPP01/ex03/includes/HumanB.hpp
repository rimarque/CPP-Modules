#ifndef HUMANB_H
# define HUMANB_H

# include "Weapon.hpp"

class HumanB {

    private:
        Weapon *_myW;
        std::string _name;

    public:
        HumanB(std::string name);
        void attack();
        void setWeapon(Weapon &myW);
        ~HumanB();
};

#endif