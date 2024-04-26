#ifndef AMATERIA_H
# define AMATERIA_H

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
# define BOLD_WHITE "\033[1;37m"
# define BOLD_CYAN "\033[1;36m"
# define RESET "\033[0m"

class ICharacter;

class AMateria {
    public:
        AMateria(); // Constructor
        AMateria(std::string const & type); //Constructor that takes a const reference to type
        AMateria(const AMateria& copy);//Copy constructor
        AMateria& operator= (const AMateria& copy); //Copy assignment constructor
        std::string const & getType() const; //Returns the materia type
        void    setType(std::string const &);
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
        virtual ~AMateria(); // Destructor

    protected:
        std::string _type;
};

#endif // AMATERIA_H
