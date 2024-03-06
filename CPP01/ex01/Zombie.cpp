#include "includes/Zombie.hpp"

Zombie::Zombie( void ){
    std::cout << "Constructing a Zombie..." << std::endl;
    return ;
}

void    Zombie::setName( std::string name){
    this->_name = name;
    return ;
}

void    Zombie::announce( void ) {
    std::cout << YELLOW << this->_name << ":" << WHITE << " Braiiiiiiinnnzzz" << RESET << std::endl;
}


Zombie::~Zombie( void ){
    std::cout << this->_name << " died by lack of brainz" << std::endl;
    return ;
}