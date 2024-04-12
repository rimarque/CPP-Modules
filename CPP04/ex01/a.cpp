    #include "a.h"

    a::a() {
        std::cout << WHITE << "a" << RESET 
        << " default constructor called" << std::endl;
    }

    // Copy constructor
    a::a(const a& copy) {
        // Copy stuff
        std::cout << WHITE << "a" << RESET 
        << " copy constructor called" << std::endl;
    }

    // Copy assignment operator overload
    a& a::operator= (const a& copy) {
        // Self-assignment check
        if (this == &copy)
            return *this;
        // Copy stuff
        std::cout << WHITE << "a" << RESET 
        << " copy assignment operator overload" << std::endl;
        return *this;
    }

    a::~a() {
        std::cout << WHITE << "a" << RESET 
        << " destructor called" << std::endl;
    }
    