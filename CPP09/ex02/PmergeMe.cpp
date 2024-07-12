#include "includes/PmergeMe.hpp"

PmergeMe::PmergeMe() {
    std::cout << BOLD_WHITE << "PmergeMe" << RESET 
    << " default constructor called" << std::endl;
}

// Copy constructor
PmergeMe::PmergeMe(const PmergeMe& copy) {
    // Copy stuff
    std::cout << BOLD_WHITE << "PmergeMe" << RESET 
    << " copy constructor called" << std::endl;
}

// Copy assignment operator overload
PmergeMe& PmergeMe::operator= (const PmergeMe& copy) {
    // Self-assignment check
    if (this == &copy)
        return *this;
    // Copy stuff
    std::cout << BOLD_WHITE << "PmergeMe" << RESET 
    << " copy assignment operator overload" << std::endl;
    return *this;
}

PmergeMe::~PmergeMe() {
    std::cout << BOLD_WHITE << "PmergeMe" << RESET 
    << " destructor called" << std::endl;
}
