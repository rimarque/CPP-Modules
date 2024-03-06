#include "includes/Zombie.hpp"

void    randomChump( std::string name ){
    std::cout << GREEN << "A random zombie will be anounced soon!" << RESET << std::endl;
    Zombie  zb(name);
    zb.announce();
}