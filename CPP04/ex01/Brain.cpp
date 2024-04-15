#include "includes/Brain.hpp"

Brain::Brain() {
    std::cout << WHITE << "Brain" << RESET 
    << " default constructor called" << std::endl;
}

// Copy constructor
Brain::Brain(const Brain& copy) {
    // Copy stuff
    std::cout << WHITE << "Brain" << RESET 
    << " copy constructor called" << std::endl;
}

// Copy assignment operator overload
Brain& Brain::operator= (const Brain& copy) {
    // Self-assignment check
    if (this == &copy)
        return *this;
    // Copy stuff
    std::cout << WHITE << "Brain" << RESET 
    << " copy assignment operator overload" << std::endl;
    return *this;
}

Brain::~Brain() {
    std::cout << WHITE << "Brain" << RESET 
    << " destructor called" << std::endl;
}