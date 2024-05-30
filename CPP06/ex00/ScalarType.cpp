#include "includes/ScalarType.hpp"

ScalarType::ScalarType(): _str(NULL), _type(-1), _precision(1), _conversions(6){
/*     std::cout << BOLD_WHITE << "ScalarType" << RESET 
    << " default constructor called" << std::endl; */
}

ScalarType::ScalarType(char *str): _str(str), _precision(1), _conversions(6){
    /* std::cout << BOLD_WHITE << "ScalarType" << RESET 
    << " constructor called for str " << _str << std::endl; */
    if(!str || str[0] == 0)
        throw MyException("Empty string");
    _type = this->detectType();
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

int         ScalarType::getConversions() const{
    return _conversions;
}

ScalarType::~ScalarType() {
    /* std::cout << BOLD_WHITE << "ScalarType" << RESET 
    << " destructor called" << std::endl; */
}
