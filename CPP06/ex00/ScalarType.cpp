#include "includes/ScalarType.hpp"

ScalarType::ScalarType(): _str(NULL), _type(-1), _precision(1), _conversions(6){}

ScalarType::ScalarType(char *str): _str(str), _precision(1), _conversions(6){
    if(!str || str[0] == 0)
        throw MyException("Empty string");
    _type = this->detectType();
}

//!Copy constructor
ScalarType::ScalarType(const ScalarType& copy)
    :   _str(copy._str), 
        _type(copy._type), 
        _precision(copy._precision), 
        _conversions(copy._conversions) {}


//!Copy assignment operator overload
ScalarType& ScalarType::operator= (const ScalarType& copy) {
    if (this == &copy)
        return *this;
    _str = copy._str; 
    _type = copy._type; 
    _precision = copy._precision; 
    _conversions = copy._conversions;
    std::cout << BOLD_WHITE << "ScalarType" << RESET 
    << " copy assignment operator overload" << std::endl;
    return *this;
}

std::string ScalarType::getStr() const{
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

ScalarType::~ScalarType() {}
