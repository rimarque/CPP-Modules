#include "includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
    std::cout << BOLD_WHITE << "ScalarConverter" << RESET 
    << " default constructor called" << std::endl;
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

void    ScalarConverter::convert(char *str){
    try{
        ScalarType  convertType(str);
        if(convertType.getType() == -1)
            throw MyException("Invalid type");
        void (ScalarType::*convertTo[])() = 
            {&ScalarType::convertToChar, &ScalarType::convertToInt, 
                &ScalarType::convertToFloat, &ScalarType::convertToDouble, 
                    &ScalarType::pseudoLiteralsFloat, &ScalarType::pseudoLiterals};
        (convertType.*convertTo[convertType.getType()])();
    }
    catch(const std::exception& e){
        std::cerr << e.what() << std::endl;
    }
}