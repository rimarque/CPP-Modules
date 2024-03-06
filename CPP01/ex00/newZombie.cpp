#include "includes/Zombie.hpp"

Zombie*  newZombie( std::string name ){
    std::cout << YELLOW << "Creating a New Zombie..." << RESET << std::endl;;
    Zombie *zb = new Zombie(name);
    return (zb);
}