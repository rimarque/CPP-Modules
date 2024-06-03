#include "includes/ScalarType.hpp"
/* To make things simple, please note that non displayable characters shouldn’t be used as
inputs */
bool    ScalarType::isChar() {
    if (_str.length() > 1)
        return false;
    char c = _str[0];
    if (std::isdigit(c) || !std::isprint(c))
        return false;
    return true;
}

bool ScalarType::isInt(){
    std::string str = getBeginNumber();
    if(hasNonNumericChar(str))
        return false;
    long long int lnum = std::atoll(_str.c_str());
    if(lnum < INT_MIN || lnum > INT_MAX)
        return false;
    return true;
}

bool ScalarType::isFloat(){
    std::string str = getBeginNumber();
    if(!checkFloatCriteria(str))
        return false;
    double dnum = atof(_str.c_str());
    if(dnum < -FLT_MAX || dnum > FLT_MAX)
        return false;
    return true;
}

bool ScalarType::isDouble(){
    std::string str = getBeginNumber();
    if(!checkDoubleCriteria(str))
        return false;
    long double ldnum = strtold(_str.c_str(), NULL);
    if(ldnum < -DBL_MAX || ldnum > DBL_MAX)
        return false;
    return true;
}

bool    ScalarType::isPseudoLiteralFloat(){
    std::string pseudoLiterals[3] = {"nanf", "+inff", "-inff"};
    for(int i = 0; i < 3; i++){
        if(!_str.compare(pseudoLiterals[i]))
            return true;
    }
    return false;
}

bool    ScalarType::isPseudoLiteral(){
    std::string pseudoLiterals[3] = {"nan", "+inf", "-inf"};
    for(int i = 0; i < 3; i++){
        if(!_str.compare(pseudoLiterals[i]))
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