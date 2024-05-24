#ifndef INVALIDOPTIONEXCEPTION_HPP
# define INVALIDOPTIONEXCEPTION_HPP

# include <stdexcept>

class InvalidOptionException: public std::exception {
        public:
            virtual const char* what() const throw();
};

class InvalidFormException: public std::exception {
        public:
            virtual const char* what() const throw();
};

#endif