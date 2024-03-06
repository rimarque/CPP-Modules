#ifndef WEAPON_H
# define WEAPON_H

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

class Weapon {
    private:
        std::string _type;
    public:
        Weapon(std::string type);
        const std::string& getType();
        void setType(std::string type);
        ~Weapon();
};

#endif