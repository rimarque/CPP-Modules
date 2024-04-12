#include "b.h"

b::b() {
    std::cout << WHITE << b << RESET 
    << "default constructor called" << std::endl;
}

//Copy constructor
b::b(const b& copy){ //const reference
    //copy stuff
    std::cout << WHITE << b << RESET 
    << "copy constructor called" << std::endl;
    return ;
}

//Copy assignment operator overload
b& b::operator= (const b& copy)
{
    // self-assignment check
    if(this == &copy)
        return *this;
    //Copy stuff
    std::cout << WHITE << b << RESET 
    << "copy assignment operator overload" << std::endl;
    return (*this);
}

b::~b() {
    std::cout << WHITE << b << RESET << "destructor called" << std::endl;
}
