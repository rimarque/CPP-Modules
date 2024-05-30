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
    std::cout << "Type: char" << std::endl;
    return true;
}

bool ScalarType::isInt(){
    std::string str = getBeginNumber(_str);
    if(hasNonNumericChar(str))
        return false;
    long long int lnum = std::atoll(_str);
    if(lnum < INT_MIN || lnum > INT_MAX)
        return false;
    std::cout << "Type: int" << std::endl;
    return true;
}

bool ScalarType::isFloat(){
    std::string str = getBeginNumber(_str);
    if(!checkFloatCriteria(str)){
        return false;
    }
    double dnum = atof(_str);
    if(dnum < -FLT_MAX || dnum > FLT_MAX){
        return false;
    }
    std::cout << "Type: float" << std::endl;
    return true;
}

bool ScalarType::isDouble(){
    std::string str = getBeginNumber(_str);
    if(!checkDoubleCriteria(str)){
        return false;
    }
    long double ldnum = strtold(_str, NULL);
    if(ldnum < -DBL_MAX || ldnum > DBL_MAX){
        return false;
    }
    std::cout << "Type: double" << std::endl;
    return true;
}

/*-inff, +inff, nanf; */
bool    ScalarType::isPseudoLiteralFloat(){
    std::string str = _str;
    std::string pseudoLiterals[3] = {"nanf", "+inff", "-inff"};
    for(int i = 0; i < 3; i++){
        if(!str.compare(pseudoLiterals[i]))
            return true;
    }
    return false;
}

/*-inf, +inf, nan; */
bool    ScalarType::isPseudoLiteral(){
    std::string str = _str;
    std::string pseudoLiterals[3] = {"nan", "+inf", "-inf"};
    for(int i = 0; i < 3; i++){
        if(!str.compare(pseudoLiterals[i]))
            return true;
    }
    return false;
}

int ScalarType::detectType() {
    bool (ScalarType::*isType[])() = 
        {&ScalarType::isChar, &ScalarType::isInt, 
            &ScalarType::isFloat, &ScalarType::isDouble, 
                &ScalarType::isPseudoLiteralFloat, &ScalarType::isPseudoLiteral};
    for(int i = 0; i < _conversions; i++) {
        if((this->*isType[i])())
                return i;
    }
    return -1;
}