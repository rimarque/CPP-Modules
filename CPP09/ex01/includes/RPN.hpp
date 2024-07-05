#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string.h>
# include <unistd.h>
# include <cstdlib>
# include <ctime>
# include <stack>
# include <queue>
# include <bits/stdc++.h>
# define RED "\033[31m"
# define GREEN "\033[32m"
# define PURPLE "\033[35m"
# define YELLOW "\033[33m"
# define WHITE "\033[37m"
# define CYAN "\033[36m"
# define BOLD_RED "\033[1;31m"
# define BOLD_GREEN "\033[1;32m"
# define BOLD_PURPLE "\033[1;35m"
# define BOLD_YELLOW "\033[1;33m"
# define BOLD_WHITE 	"\033[1;37m"
# define BOLD_CYAN "\033[1;36m"
# define RESET "\033[0m"

# include <stdexcept>
class MyException: public std::exception {
    public:
        explicit MyException(const std::string& msg);
        virtual const char* what() const throw();
        virtual ~MyException() throw();
    private:
        std::string _msg;
};

class RPN {
public:
    RPN(); // Constructor
    RPN(const RPN& copy);//Copy constructor
    RPN& operator= (const RPN& copy); //Copy assignment constructor
    float calculate(std::queue<int> q);
    ~RPN(); // Destructor

private:
    std::stack<float> _stack;
};

#endif // RPN_HPP
