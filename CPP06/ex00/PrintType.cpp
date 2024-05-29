#include "includes/ScalarType.hpp"

void    ScalarType::printChar(int num){
    if(num > 31 && num < 127)
        std::cout << "char: " << static_cast<char>(num) << std::endl;
    else if (num >= 0 && num <= 255)
        std::cout << "char: Non displayable" << std::endl;
    else if (num < 0 || num > 255)
        std::cout << "char: impossible" << std::endl;
}

void    ScalarType::printInt(long long int lnum){
    if(lnum >= INT_MIN && lnum <= INT_MAX)
        std::cout << "int: " << static_cast<int>(lnum) << std::endl;
    else
        std::cout << "int: impossible" << std::endl;
}

void    ScalarType::printFloat(double dnum){
    if(dnum >= FLT_MIN || dnum <= FLT_MAX)
        std::cout << "int: " << static_cast<float>(dnum) << std::endl;
    else
        std::cout << "int: impossible" << std::endl;
}