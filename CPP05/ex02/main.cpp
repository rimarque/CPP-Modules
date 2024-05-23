#include "includes/PresidentialPardonForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/ShrubberyCreationForm.hpp"
#include "includes/InvalidOptionException.hpp"

int main()
{
  std::string input;
  try{
    std::cout << "What form should we test?" << std::endl 
    << "1: Presidential Pardon Form\n2: Robotomy Request Form\n3: ShrubberyCreationForm\n4: All forms\n.:";
    std::cin >> input;
    if(std::cin.eof())
	    exit(0);
    int option = std::atoll(input.c_str()) > 3 || std::atoll(input.c_str()) < 1 ? -1 : std::atoi(input.c_str());
    if (option == -1)
      throw InvalidOptionException();
    if(option == 1 || option == 4)
      testPresidentialPardonForm();
    if(option == 2 || option == 4)
      testRobotomyRequestForm();
    if(option == 3 || option == 4)
      testShrubberyCreationForm();
  }
  catch (const std::exception& e) {
    std::cerr << std::endl << e.what() << std::endl << std::endl;
  }
}