#include "c.h"

c::c() {
    std::cout << WHITE << c << RESET 
    << "default constructor called" << std::endl;
}

//Copy constructor
c::c(const c& copy){ //const reference
    //copy stuff
    std::cout << WHITE << c << RESET 
    << "copy constructor called" << std::endl;
    return ;
}

//Copy assignment operator overload
c& c::operator= (const c& copy)
{
    // self-assignment check
    if(this == &copy)
        return *this;
    //Copy stuff
    std::cout << WHITE << c << RESET 
    << "copy assignment operator overload" << std::endl;
    return (*this);
}

c::~c() {
    std::cout << WHITE << c << RESET << "destructor called" << std::endl;
}
