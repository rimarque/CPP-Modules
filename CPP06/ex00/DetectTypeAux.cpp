#include "includes/ScalarType.hpp"

std::string ScalarType::getBeginNumber(std::string str){
    int i = 0;
    while(std::isspace(_str[i]))
        i++;
    if(_str[i] == '-' || _str[i] == '+')
        i++;
    return str.substr(i);
}

bool    ScalarType::hasNonNumericChar(std::string str)
{
  for (std::string::const_iterator i = str.begin(); i != str.end(); ++i) {
        if (!std::isdigit(*i))
            return true;
  }
  return false;
}

int getMaxValue(int a, int b){
    if(a > b)
        return(a);
    return(b);
}

/* -inff, +inff, nanf;*/
bool  ScalarType::checkFloatCriteria(std::string str)
{
    std::string::const_iterator i = str.begin();
    std::string::const_iterator next = i;
    ++next;
    bool    point = false;
    while (next != str.end()){
        if (!std::isdigit(*i) && *i != '.')
            return false;
        //ponto n pode repetir; pode estar no inicio ou no fim
        if(*i == '.'){
            if (point == true)
                return false;
            point = true;
            //set precision
            _precision = getMaxValue(str.length() - str.find('.') - 2, 1);
        }
        ++next;
        ++i;
    }
    if((*i == 'f' || *i == 'F') && point == true)
        return true;
    return false;
}


bool  ScalarType::checkDoubleCriteria(std::string str)
{
    bool    point = false;
    for (std::string::const_iterator i = str.begin(); i != str.end(); ++i){
        if (!std::isdigit(*i) && *i != '.')
            return false;
        //ponto n pode repetir; pode estar no inicio ou no fim
        if(*i == '.'){
            if (point == true)
                return false;
            point = true;
            //set precision
            _precision = getMaxValue(str.length() - str.find('.') - 1, 1);
        }
    }
    if(point == true)
        return true;
    return false;
}
