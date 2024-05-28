#include "includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
    std::cout << BOLD_WHITE << "ScalarConverter" << RESET 
    << " default constructor called" << std::endl;
}

// Copy constructor
ScalarConverter::ScalarConverter(const ScalarConverter& copy) {
    *this = copy;
    std::cout << BOLD_WHITE << "ScalarConverter" << RESET 
    << " copy assigment operator called" << std::endl;
}

// Copy assignment operator overload
ScalarConverter& ScalarConverter::operator= (const ScalarConverter& copy) {
    // Self-assignment check
    if (this == &copy)
        return *this;
    *this = copy;
    std::cout << BOLD_WHITE << "ScalarConverter" << RESET 
    << " copy assignment operator overload" << std::endl;
    return *this;
}

/* To make things simple, please note that non displayable characters shouldn’t be used as
inputs */
//*1.Detect the type;
bool ScalarConverter::isChar(char *str){
    if (std::strlen(str) > 1){
        return false;
    }
    char c = str[0];
    if (std::isdigit(c) || !std::isprint(c))
        return false;
    std::cout << "is char!" << std::endl;
    return true;
}

bool  hasNonNumericChar(std::string str)
{
  for (std::string::const_iterator i = str.begin(); i != str.end(); ++i) {
        if (!std::isdigit(*i))
            return true;
  }
  return false;
}
//setPercision
bool  checkFloatCriteria(std::string str)
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
            //_precision = str.lenght() - str.find('.');
        }
        ++next;
        ++i;
    }
    if(*i == 'f' || *i == 'F')
        return true;
    return false;
}

bool  isIntNumber(std::string str){
  int i = 0;
  while(std::isspace(str[i]))
    i++;
  if(str[i] == '-' || str[i] == '+')
    i++;
  if(hasNonNumericChar(str.substr(i)))
    return false;
  return true;
}

bool  isFloatNumber(std::string str){
  int i = 0;
  while(std::isspace(str[i]))
    i++;
  if(str[i] == '-' || str[i] == '+')
    i++;
  if(checkFloatCriteria(str.substr(i)))
    return true;
  return false;
}

bool ScalarConverter::isInt(char *str){
    if (!isIntNumber(str))
        return false;
    long long int lnum = std::atoll(str);
    if(lnum < INT_MIN || lnum > INT_MAX)
        return false;
    std::cout << "is int!" << std::endl;
    return true;
}

//One point
//F or f
//Limits
bool ScalarConverter::isFloat(char *str){
    if(!isFloatNumber(str))
        return false;
    double dnum = atof(str);
    if(dnum < FLT_MIN || dnum > FLT_MAX)
        return false;
    return true;
}

bool ScalarConverter::isDouble(char *str){
    (void)str;
    //std::cout << "is double: " << str << std::endl;
    return(false);
}

int ScalarConverter::getType(char *str) {
    bool (*isType[])(char *) = 
        {&ScalarConverter::isChar, &ScalarConverter::isInt, 
            &ScalarConverter::isFloat, &ScalarConverter::isDouble};
    for(int i = 0; i < 4; i++) {
        if((*isType[i])(str))
                return i;
    }
    return -1;
}

/* int num = atoi(str);
float fnum = atof(str);
double dnum = strtod(str, NULL); or atof()*/
/* strtod() provides more control and error handling. 
It allows you to check if the conversion was successful by examining the second
argument (a pointer to the first character after the converted value), 
which will be set to NULL if no conversion was performed. */


//*2.Convert to the right type; 
//!check nondisplayable; check impossible (overflow);
//static_cast<char> converts to unseigned char (range 0 to 255)
//*3.Convert explicitly to the other 3 types, example: static_cast<float>(integerVal);
//*4.Display the result

//*Done
void    ScalarConverter::convertToChar(char *str){
    std::cout << "1: convert to char: \n";
    char c = str[0];
    std::cout << "char: " << c << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void    printChar(int num){
    if(num > 31 && num < 127)
        std::cout << "char: " << static_cast<char>(num) << std::endl;
    else if (num >= 0 && num <= 255)
        std::cout << "char: Non displayable" << std::endl;
    else if (num < 0 || num > 255)
        std::cout << "char: impossible" << std::endl;
}

void    printInt(long long int lnum){
    if(lnum >= INT_MIN && lnum <= INT_MAX)
        std::cout << "int: " << static_cast<int>(lnum) << std::endl;
    else
        std::cout << "int: impossible" << std::endl;
}

void    printFloat(double dnum){
    if(dnum >= FLT_MIN || dnum <= FLT_MAX)
        std::cout << "int: " << static_cast<float>(dnum) << std::endl;
    else
        std::cout << "int: impossible" << std::endl;
}

//*Done
void    ScalarConverter::convertToInt(char *str){
    std::cout << "2: convert to int: \n";
    int num = atoi(str);
    printChar(num);
    std::cout << "int: " << num << std::endl;
    std::cout << "float: " << static_cast<float>(num) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(num) << ".0" << std::endl;
}

void    ScalarConverter::convertToFloat(char *str){
    std::cout << "3: convert to float: \n";
    double fnum = atof(str);

    printChar(static_cast<int>(fnum));
    printInt(static_cast<long long int>(fnum));
    std::cout << "float: " << std::fixed << std::setprecision(1)
        << fnum << str[strlen(str) - 1] << std::endl;
    std::cout << "double: " << static_cast<double>(fnum) << std::endl;
}

void    ScalarConverter::convertToDouble(char *str){
    std::cout << "4: convert to double: \n";
    double dnum = strtod(str, NULL);
    printChar(static_cast<int>(dnum));
    printInt(static_cast<long long int>(dnum));
    printFloat(dnum);
    std::cout << "double: " << dnum << std::endl;
}

/* -inff, +inff, nanf;
-inf, +inf, nan; */

void    ScalarConverter::convert(char *str){
    try{
        int type = ScalarConverter::getType(str);
        if(type == -1)
            throw MyException("Not a valid type");
        void (*convertTo[])(char *) = 
            {&ScalarConverter::convertToChar, &ScalarConverter::convertToInt, 
                &ScalarConverter::convertToFloat, &ScalarConverter::convertToDouble};
        (*convertTo[type])(str);
        //std::cout << str << std::endl;
    }
    catch(const std::exception& e){
        std::cerr << e.what() << std::endl;
    }
}


ScalarConverter::~ScalarConverter() {
    std::cout << BOLD_WHITE << "ScalarConverter" << RESET 
    << " destructor called" << std::endl;
}
