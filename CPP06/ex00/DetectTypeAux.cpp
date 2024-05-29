#include "includes/ScalarType.hpp"

bool    ScalarType::hasNonNumericChar(std::string str)
{
  for (std::string::const_iterator i = str.begin(); i != str.end(); ++i) {
        if (!std::isdigit(*i))
            return true;
  }
  return false;
}

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
            _precision = str.length() - str.find('.');
        }
        ++next;
        ++i;
    }
    if(*i == 'f' || *i == 'F')
        return true;
    return false;
}

std::string ScalarType::getBeginNumber(std::string str){
    int i = 0;
    while(std::isspace(_str[i]))
        i++;
    if(_str[i] == '-' || _str[i] == '+')
        i++;
    return str.substr(i);
}