#include "includes/ScalarType.hpp"

void    ScalarType::convertToChar(){
    std::cout << "1: convert to char: \n";
    char c = _str[0];
    std::cout << "char: " << c << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(_precision) 
        << static_cast<float>(c) << "f" <<std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void    ScalarType::convertToInt(){
    std::cout << "2: convert to int: \n";
    int num = atoi(_str.c_str());
    checkLimitsPrintChar(num);
    std::cout << "int: " << num << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(_precision)
        << static_cast<float>(num) << "f" <<std::endl;
    std::cout << "double: " << static_cast<double>(num) << std::endl;
}

void    ScalarType::convertToFloat(){
    std::cout << "3: convert to float: \n";
    float fnum = atof(_str.c_str());

    checkLimitsPrintChar(static_cast<int>(fnum));
    checkLimitsPrintInt(static_cast<long long int>(fnum));
    std::cout << "float: " << std::fixed << std::setprecision(_precision)
        << fnum << _str[strlen(_str.c_str()) - 1] << std::endl;
    std::cout << "double: " << static_cast<double>(fnum) << std::endl;
}

void    ScalarType::convertToDouble(){
    std::cout << "4: convert to double: \n";
    double dnum = strtod(_str.c_str(), NULL);
    checkLimitsPrintChar(static_cast<int>(dnum));
    checkLimitsPrintInt(static_cast<long long int>(dnum));
    checkLimitsPrintFloat(dnum, _precision);
    std::cout << std::fixed << std::setprecision(_precision) 
        << "double: " << dnum << std::endl;
}

void    ScalarType::pseudoLiteralsFloat(){
    std::string str = _str;
    std::cout << "char: " << "impossible" << std::endl;
    std::cout << "int: " << "impossible" << std::endl;
    std::cout << "float: " << _str << std::endl;
    std::cout << "double: " <<  str.erase(str.size() - 1)<< std::endl;
}

void    ScalarType::pseudoLiterals(){
    std::cout << "char: " << "impossible" << std::endl;
    std::cout << "int: " << "impossible" << std::endl;
    std::cout << "float: " << _str << "f"<< std::endl; 
    std::cout << "double: " << _str << std::endl;
}