#ifndef BRAIN_H
# define BRAIN_H

# include <iostream>
# include <string.h>
# include <unistd.h>
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define PURPLE "\033[1;35m"
# define YELLOW "\033[1;33m"
# define WHITE 	"\033[1;37m"
# define CYAN "\033[1;36m"
# define RESET "\033[0m"

class Brain {
private:
    std::string _ideas[100];
public:
    Brain(); // Constructor
    Brain(const Brain& copy);//Copy constructor
    Brain&  operator= (const Brain& copy); //Copy assignment constructor
    void    displayIdeas() const;
    ~Brain(); // Destructor
};

#endif // BRAIN_H
    