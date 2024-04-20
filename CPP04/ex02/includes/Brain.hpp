#ifndef BRAIN_H
# define BRAIN_H

# include <iostream>
# include <string.h>
# include <unistd.h>
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
# define BOLD_WHITE "\033[1;37m"
# define BOLD_CYAN "\033[1;36m"
# define RESET "\033[0m"

class Brain {
private:
    std::string _ideas[100];
public:
    Brain(); // Constructor
    Brain(const Brain& copy);//Copy constructor
    Brain&  operator= (const Brain& copy); //Copy assignment constructor
    void    displayIdeas() const;
    void    setIdeas(std::string ideas);
    ~Brain(); // Destructor
};

#endif // BRAIN_H
    