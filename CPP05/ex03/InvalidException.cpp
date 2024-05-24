#include "includes/InvalidException.hpp"

const char* InvalidOptionException::what() const throw(){
    return "\033[1;31mInvalid option!\033[0m";
}

const char* InvalidFormException::what() const throw(){
    return "\033[1;31mInvalid form name!\033[0m";
}

