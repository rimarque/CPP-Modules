#include "includes/ICharacter.hpp"

ICharacter::~ICharacter() {
    std::cout << WHITE << "ICharacter" << RESET 
    << " destructor called" << std::endl;
}
