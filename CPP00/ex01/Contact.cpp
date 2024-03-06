#include "includes/PhoneBook.hpp"

Contact::Contact(void) {
	return;
}

Contact::Contact( std::string fn, std::string ln, std::string nick, std::string nb, std::string ds): _firstName(fn),
																									_lastName(ln),
																									_nickname(nick),
																									_number(nb),
																									_darkestSc(ds) {
	return;
}

void	Contact::print_field(int field){
	std::string str;

	if(field == 1)
		str = this->_firstName.length() > 10 ? this->_firstName.substr(0, 9).append(".") : this->_firstName;
	if(field == 2)
		str = this->_lastName.length() > 10 ? this->_lastName.substr(0, 9).append(".") : this->_lastName;
	if(field == 3)
		str = this->_nickname.length() > 10 ? this->_nickname.substr(0, 9).append(".") : this->_nickname;
	std::cout << "|" << std::setw(10) << str;
}

void	Contact::display_contact(int index){

	if(this->_firstName.length() <= 0)
	{
		std::cout << std::endl << RED << "ERROR: " << RESET << std::endl;
		sleep(1);
		std::cout << "NO CONTACT ASSOCIATED" << std::endl;
		sleep(1);
		return ;
	}
	std::cout << "\n─────────" << YELLOW " Contact Information for Index " << index << RESET << " ─────────\n";
	std::cout << WHITE << "\t\tFirst Name: " << RESET << this->_firstName << std::endl;
	std::cout << WHITE << "\t\tLast Name: " << RESET << this->_lastName << std::endl;
	std::cout << WHITE << "\t\tNickname: " << RESET << this->_nickname << std::endl;
	std::cout << WHITE << "\t\tNumber: " << RESET << this->_number << std::endl;
	std::cout << WHITE << "\t\tDarkest Secret: " << RESET << this->_darkestSc << std::endl;
	sleep(1);
}

Contact::~Contact(void){
	return;
}