#include "includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
    std::cout << BOLD_WHITE << "ScalarConverter" << RESET 
    << " default constructor called" << std::endl;
}

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