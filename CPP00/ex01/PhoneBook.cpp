#include "includes/PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
	this->_i = 0;
	return;
}

void	PhoneBook::add(void) {

	std::string first_n, last_n, nickname, number, darkest_sc;

	std::system("clear");
	std::cout << GREEN << "»»———————————— - ADD CONTACT - ————————————««\n\n" << RESET;
	std::cout << "First Name: ";
	std::getline(std::cin, first_n);
	if(std::cin.eof())
		exit(0);
	std::cin.clear();
	std::cout << "Last Name: ";
	std::getline(std::cin, last_n);
	if(std::cin.eof())
		exit(0);
	std::cin.clear();
	std::cout << "Nickname: ";
	std::getline(std::cin, nickname);
	if(std::cin.eof())
		exit(0);
	std::cin.clear();
	std::cout << "Number: ";
	std::getline(std::cin, number);
	if(std::cin.eof())
		exit(0);
	std::cin.clear();
	std::cout << "Darkest Secret: ";
	std::getline(std::cin, darkest_sc);
	if(std::cin.eof())
		exit(0);
	std::cin.clear();
	if (first_n.empty() || last_n.empty() || nickname.empty()
		|| number.empty() || darkest_sc.empty()) {
			std::cout << std::endl << RED << "ERROR: " << RESET << std::endl;
			sleep(1);
			std::cout << "EMPTY PARAMETER" << std::endl;
			sleep(1);
			return ;
	}
	if (check_digits(number)) {
			std::cout << std::endl << RED << "ERROR: " << RESET << std::endl;
			sleep(1);
			std::cout << "INVALID NUMBER" << std::endl;
			sleep(1);
			return ;
	}
	this->_contacts[_i++ % 8] = Contact(first_n, last_n, nickname, number, darkest_sc);
	std::system("clear");
	std::cout << "\n\t\t  " << first_n << GREEN << "'s CONTACT WAS SUCCESSFULLY ADDED\n" << RESET;
	sleep(1);
}

void	PhoneBook::search(void){

	int i, index;
	std::string input;

	std::system("clear");
	std::cout << YELLOW << "\t»»——————————————— - SEARCH - ——————————————««\n\n" << RESET;
	std::cout << WHITE << "\t|" << std::setw(10) << "Index" << "|" << std::setw(10) << "First Name" << "|" << std::setw(10) << "Last Name" << "|" << std::setw(10) << "Nickname" << "|" << RESET << std::endl;
	for(i = 0; i < 8; i++)
	{
		std::cout << "\t|" << std::setw(10) << i + 1;
		this->_contacts[i].print_field(1);
		this->_contacts[i].print_field(2);
		this->_contacts[i].print_field(3);
		std::cout << "|" << std::endl;
	}
	std::cout << YELLOW << "\n\n\t\t  Who do you want to know?\n" << RESET << "\t      Choose the index and get the info\n";
	std::cout << ".: ";
	std::cin.clear();
	std::getline(std::cin, input);
	if(std::cin.eof())
		exit(0);
	index = std::atoll(input.c_str()) > 8 || std::atoll(input.c_str()) < 1 ? -1 : std::atoi(input.c_str());
	if(index == -1) {
		std::cout << std::endl << RED << "ERROR: " << RESET << std::endl;
		sleep(1);
		std::cout << "INVALID INDEX" << std::endl;
		sleep(1);
		return ;
	}
	std::system("clear");
	this->_contacts[std::atoi(input.c_str()) - 1].display_contact(index);
}

PhoneBook::~PhoneBook(void){
	return; 
}
