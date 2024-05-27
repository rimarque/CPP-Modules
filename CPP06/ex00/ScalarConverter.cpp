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

//*1.Detect the type; Detect overflows;
bool ScalarConverter::isChar(char *str){
    std::cout << "is char: " << str << std::endl;
    return(false);
}

bool ScalarConverter::isInt(char *str){
    std::cout << "is int: " << str << std::endl;
    return(true);
}

bool ScalarConverter::isFloat(char *str){
    std::cout << "is float: " << str << std::endl;
    return(false);
}

bool ScalarConverter::isDouble(char *str){
    std::cout << "is double: " << str << std::endl;
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


//*2.Convert to the right type; check nondisplayable; check impossible; check overflow;
//*3.Convert explicitly to the other 3 types, example: static_cast<float>(integerVal);
//*4.Display the result

bool    nonDisplayable(char c){
    if(c < 32 || c == 127)
        return true;
    return false;
}

void    ScalarConverter::convertToChar(char *str){
    std::cout << "1: convert to char: \n";
    char c = str[0];
    if(nonDisplayable(c))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: " << c << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void    ScalarConverter::convertToInt(char *str){
    std::cout << "2: convert to int: \n";
    int num = atoi(str);
    std::cout << "char: " << static_cast<char>(num) << std::endl;
    std::cout << "int: " << num << std::endl;
    std::cout << "float: " << static_cast<float>(num) << std::endl;
    std::cout << "double: " << static_cast<double>(num) << std::endl;
}

void    ScalarConverter::convertToFloat(char *str){
    std::cout << "3: convert to float: \n";
    float fnum = atof(str);
    std::cout << "char: " << static_cast<char>(fnum) << std::endl;
    std::cout << "int: " << static_cast<int>(fnum) << std::endl;
    std::cout << "float: " << fnum << std::endl;
    std::cout << "double: " << static_cast<double>(fnum) << std::endl;
}

void    ScalarConverter::convertToDouble(char *str){
    std::cout << "4: convert to double: \n";
    double dnum = strtod(str, NULL);
    std::cout << "char: " << static_cast<char>(dnum) << std::endl;
    std::cout << "int: " << static_cast<int>(dnum) << std::endl;
    std::cout << "float: " << static_cast<float>(dnum) << std::endl;
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
