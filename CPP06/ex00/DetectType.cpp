#include "includes/ScalarType.hpp"
/* To make things simple, please note that non displayable characters shouldn’t be used as
inputs */
bool    ScalarType::isChar() {
    if (std::strlen(_str) > 1){
        return false;
    }
    char c = _str[0];
    if (std::isdigit(c) || !std::isprint(c))
        return false;
    std::cout << "is char!" << std::endl;
    return true;
}

bool ScalarType::isInt(){
    std::string str = getBeginNumber(_str);
    if(hasNonNumericChar(str))
        return false;
    long long int lnum = std::atoll(_str);
    if(lnum < INT_MIN || lnum > INT_MAX)
        return false;
    std::cout << "is int!" << std::endl;
    return true;
}

bool ScalarType::isFloat(){
    std::string str = getBeginNumber(_str);
    if(!checkFloatCriteria(str))
        return false;
    double dnum = atof(_str);
    if(dnum < FLT_MIN || dnum > FLT_MAX)
        return false;
    std::cout << "is float!" << std::endl;
    return true;
}

bool ScalarType::isDouble(){
    (void)_str;
    //std::cout << "is double: " << str << std::endl;
    return(false);
}

int ScalarType::detectType() {
    bool (ScalarType::*isType[])() = 
        {&ScalarType::isChar, &ScalarType::isInt, 
            &ScalarType::isFloat, &ScalarType::isDouble};
    for(int i = 0; i < 4; i++) {
        if((this->*isType[i])())
                return i;
    }
    return -1;
}