#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>
# include <string>
# include <cctype>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <iomanip> 
# include <cstdlib>
# include <ctime>
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define PURPLE "\033[1;35m"
# define YELLOW "\033[1;33m"
# define WHITE 	"\033[1;37m"
# define CYAN "\033[1;36m"
# define RESET "\033[0m"

class Zombie {

private:
    std::string _name;

public:
    Zombie(void);  //Constructor
    ~Zombie(void); //Destructor
    void    announce(void);
    void    setName(std::string name);
};

Zombie* zombieHorde(int N, std::string name);

#endif