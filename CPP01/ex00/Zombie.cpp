#include "includes/Zombie.hpp"

Zombie::Zombie(std::string name): _name(name){
    std::cout << "Constructing a Zombie named " << name << std::endl;
    return ;
}

void    Zombie::announce( void ) {
    std::cout << GREEN << this->_name << ":" << WHITE << " Braiiiiiiinnnzzz" << RESET << std::endl;
}


Zombie::~Zombie( void ){
    std::cout << this->_name << " died by lack of brainz" << std::endl;
    return ;
}