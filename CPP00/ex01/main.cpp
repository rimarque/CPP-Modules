#include "includes/PhoneBook.hpp"

bool check_digits(std::string number){
	unsigned int	i = 0;
	if (number[0] == '+')
		i++;
	while (i < number.length()){
		if (!isdigit(number[i]))
			return (true);
		i++;
	}
	return (false);
}

int main()
{
	PhoneBook PB;
	std::string input;
	bool first = true;

	std::system("clear");
	std::cout << "─────────" << PURPLE " Welcome to your crappy awesome phonebook software " << RESET << "─────────\n";
	while (1)
	{
		if(first){
			first = false;
			std::cout << "\n\t\t\tWhat do you want to do?\n\t\t\t";
			std::cout << GREEN << "   ADD" << RESET << ", ";
		}
		else{
			std::cout << "\n\t\t\tWhat do you want to do next?\n\t\t\t";
			std::cout << GREEN << "     ADD" << RESET << ", ";
		}
		std::cout << YELLOW << "SEARCH" << RESET << ", ";
		std::cout << RED << "EXIT\n" << RESET;
		std::cout << ".: ";
		std::getline(std::cin, input);
		if(std::cin.eof())
			exit(0);
		std::cin.clear();
		if (input.compare("ADD") == 0 || input.compare("add") == 0)
			PB.add();
		else if (input.compare("SEARCH") == 0 || input.compare("search") == 0)
			PB.search();
		else if (input.compare("EXIT") == 0 || input.compare("exit") == 0)
			return (0);
		else {
			std::cout << std::endl << RED << "ERROR: " << RESET << std::endl;
			sleep(1);
			std::cout << "Nothing on keyword: \""<< WHITE << input << RESET << "\"" << std::endl;
			std::cout << "───────────────────────────────" << PURPLE << " TRY AGAIN " << RESET << "───────────────────────────\n";
		}
	}
}