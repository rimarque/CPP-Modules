#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name){
    this->_myW = NULL;
}

void HumanB::attack(){
    if(this->_myW)
        std::cout << this->_name << " attacks with their " << this->_myW->getType()  << std::endl;
    else
        std::cout << this->_name << " is defenceless, give him a weapon to help him fight!" << std::endl;
}

void HumanB::setWeapon(Weapon &myW){
    this->_myW = &myW;
}

HumanB::~HumanB(){
}