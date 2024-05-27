#include "includes/MyException.hpp"

MyException::MyException(const std::string& msg): _msg(msg) {}

const char* MyException::what() const throw(){
    return _msg.c_str();
}

MyException::~MyException() throw() {}