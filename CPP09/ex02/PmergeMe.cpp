#include "includes/PmergeMe.hpp"

MyException::MyException(): _msg("Error") {}

MyException::MyException(const std::string& msg): _msg(msg) {}

const char* MyException::what() const throw(){
    return _msg.c_str();
}

MyException::~MyException() throw() {}