#ifndef CONTACT_H
# define CONTACT_H

# include "PhoneBook.hpp"

class Contact {

private:
	std::string		_firstName;
	std::string		_lastName;
	std::string		_nickname;
	std::string		_number;
	std::string		_darkestSc;

public:
    Contact(void); //Constructor
	Contact(std::string fn, std::string ln, std::string nick, std::string nb, std::string ds);
    ~Contact(void); //Destructor
	void			print_field(int field);
	void			display_contact(int index);

};

#endif