#include "includes/ScalarType.hpp"

ScalarType::ScalarType(): _str(NULL), _type(-1), _precision(0) {
    std::cout << BOLD_WHITE << "ScalarType" << RESET 
    << " default constructor called" << std::endl;
}

ScalarType::ScalarType(char *str): _str(str), _precision(0) {
    _type = this->detectType();
    std::cout << BOLD_WHITE << "ScalarType" << RESET 
    << " default constructor called" << std::endl;
}

//!Copy constructor
ScalarType::ScalarType(const ScalarType& copy) {
    (void)copy;
    std::cout << BOLD_WHITE << "ScalarType" << RESET 
    << " copy assigment operator called" << std::endl;
}


//!Copy assignment operator overload
ScalarType& ScalarType::operator= (const ScalarType& copy) {
    (void)copy;
    // Self-assignment check
    if (this == &copy)
        return *this;
    // Copy stuff
    std::cout << BOLD_WHITE << "ScalarType" << RESET 
    << " copy assignment operator overload" << std::endl;
    return *this;
}

char        *ScalarType::getStr() const{
    return _str;
}

int         ScalarType::getType() const{
    return _type;
}

int         ScalarType::getPrecision() const{
    return _precision;
}

ScalarType::~ScalarType() {
    std::cout << BOLD_WHITE << "ScalarType" << RESET 
    << " destructor called" << std::endl;
}
