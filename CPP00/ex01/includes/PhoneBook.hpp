#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include <string>
# include <cctype>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <iomanip> 
# include <cstdlib>
# include "Contact.hpp"
# define CLEAR_SCREEN "\033[2J\033[H"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define PURPLE "\033[1;35m"
# define YELLOW "\033[1;33m"
# define WHITE 	"\033[1;37m"
# define RESET "\033[0m"

class PhoneBook {

private:
	int		_i;
	Contact _contacts[8];

public:
    PhoneBook(void); //Constructor
    ~PhoneBook(void); //Destructor
	void	add( void );
	void	search( void );
};

bool check_digits(std::string number);

#endif