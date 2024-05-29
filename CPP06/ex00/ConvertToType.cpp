#include "includes/ScalarType.hpp"

void    ScalarType::convertToChar(){
    std::cout << "1: convert to char: \n";
    char c = _str[0];
    std::cout << "char: " << c << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void    ScalarType::convertToInt(){
    std::cout << "2: convert to int: \n";
    int num = atoi(_str);
    printChar(num);
    std::cout << "int: " << num << std::endl;
    std::cout << "float: " << static_cast<float>(num) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(num) << ".0" << std::endl;
}

void    ScalarType::convertToFloat(){
    std::cout << "3: convert to float: \n";
    double fnum = atof(_str);

    printChar(static_cast<int>(fnum));
    printInt(static_cast<long long int>(fnum));
    std::cout << "float: " << std::fixed << std::setprecision(1)
        << fnum << _str[strlen(_str) - 1] << std::endl;
    std::cout << "double: " << static_cast<double>(fnum) << std::endl;
}

void    ScalarType::convertToDouble(){
    std::cout << "4: convert to double: \n";
    double dnum = strtod(_str, NULL);
    printChar(static_cast<int>(dnum));
    printInt(static_cast<long long int>(dnum));
    printFloat(dnum);
    std::cout << "double: " << dnum << std::endl;
}