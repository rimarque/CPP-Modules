#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& myW): _myW(myW), _name(name){
}

void HumanA::attack(){
    std::cout << this->_name << " attacks with their " << this->_myW.getType() << std::endl;
}

HumanA::~HumanA(){
}