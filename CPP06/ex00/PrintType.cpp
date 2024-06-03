#include "includes/ScalarType.hpp"

void    ScalarType::checkLimitsPrintChar(int num){
    if(num > 31 && num < 127)
        std::cout << "char: " << static_cast<char>(num) << std::endl;
    else if (num >= 0 && num <= 255)
        std::cout << "char: Non displayable" << std::endl;
    else if (num < 0 || num > 255)
        std::cout << "char: impossible" << std::endl;
}

void    ScalarType::checkLimitsPrintInt(long long int lnum){
    if(lnum >= INT_MIN && lnum <= INT_MAX)
        std::cout << "int: " << static_cast<int>(lnum) << std::endl;
    else
        std::cout << "int: impossible" << std::endl;
}

void    ScalarType::checkLimitsPrintFloat(double dnum, int precision){
    if(dnum >= -FLT_MAX && dnum <= FLT_MAX){
        std::cout << "float: " << std::fixed << std::setprecision(precision)
        << static_cast<float>(dnum) << "f" << std::endl;
    }
    else
        std::cout << "float: impossible" << std::endl;
}