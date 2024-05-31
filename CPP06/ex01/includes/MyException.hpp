#ifndef MYEXCEPTION_HPP
# define MYEXCEPTION_HPP

# include <stdexcept>

class MyException: public std::exception {
    public:
        explicit MyException(const std::string& msg);
        virtual const char* what() const throw();
        virtual ~MyException() throw();
    private:
        std::string _msg;
};

#endif