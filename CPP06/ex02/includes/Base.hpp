#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <string.h>
# include <unistd.h>
# include <cstdlib>
# include <ctime>
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
# define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

class Base {
public:
    virtual ~Base(); // Destructor
};

Base *generate(void);
void identify(Base* p);
void identify(Base& p);

#endif // BASE_HPP
