#include "includes/PresidentialPardonForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/ShrubberyCreationForm.hpp"
#include "includes/InvalidException.hpp"
#include "includes/Intern.hpp"

void    testPresidentialPardonForm()
{
  std::cout << BOLD_PURPLE << std::endl << std::endl 
  << "      **TESTING PRESIDENCIAL PARDON FORM**" << RESET << std::endl;

  std::cout << CYAN << std::endl << "-------CREATING INTERN" << RESET << std::endl;
  Intern  someRandomIntern;
  std::cout << CYAN << std::endl << "-------INTERN CREATING FORMS" << RESET << std::endl;
  std::cout << GREEN << std::endl << "-------Creating a Form with target rita" << RESET << std::endl;
  AForm *form1 = someRandomIntern.makeForm("presidential pardon", "rita");
  std::cout << GREEN << std::endl << "-------Creating a Form with target xico" << RESET << std::endl;
  AForm *form2 = someRandomIntern.makeForm("presidential pardon", "xico");
  std::cout << GREEN << std::endl << "-------Creating a Form with target jenny" << RESET << std::endl;
  AForm *form3 = someRandomIntern.makeForm("presidential pardon", "jenny");
  testForm(form1, form2, form3);
  delete form1;
  delete form2;
  delete form3;
}

void    testRobotomyRequestForm()
{
  std::cout << BOLD_PURPLE << std::endl << std::endl 
  << "      **TESTING ROBOTOMY REQUEST FORM**" << RESET << std::endl;

  std::cout << CYAN << std::endl << "-------CREATING INTERN" << RESET << std::endl;
  Intern  someRandomIntern;
  std::cout << CYAN << std::endl << "-------INTERN CREATING FORMS" << RESET << std::endl;
  std::cout << GREEN << std::endl << "-------Creating a Form with target rita" << RESET << std::endl;
  AForm *form1 = someRandomIntern.makeForm("robotomy request", "rita");
  std::cout << GREEN << std::endl << "-------Creating a Form with target xico" << RESET << std::endl;
  AForm *form2 = someRandomIntern.makeForm("robotomy request", "xico");
  std::cout << GREEN << std::endl << "-------Creating a Form with target jenny" << RESET << std::endl;
  AForm *form3 = someRandomIntern.makeForm("robotomy request", "jenny");
  testForm(form1, form2, form3);
  delete form1;
  delete form2;
  delete form3;
}

void    testShrubberyCreationForm()
{
  std::cout << BOLD_PURPLE << std::endl << std::endl 
  << "      **TESTING SHRUBBERY CREATION FORM**" << RESET << std::endl;

  std::cout << CYAN << std::endl << "-------CREATING INTERN" << RESET << std::endl;
  Intern  someRandomIntern;
  std::cout << CYAN << std::endl << "-------INTERN CREATING FORMS" << RESET << std::endl;
  std::cout << GREEN << std::endl << "-------Creating a Form with target yard" << RESET << std::endl;
  AForm *form1 = someRandomIntern.makeForm("shrubbery creation", "yard");
  std::cout << GREEN << std::endl << "-------Creating a Form with target school" << RESET << std::endl;
  AForm *form2 = someRandomIntern.makeForm("shrubbery creation", "school");
  std::cout << GREEN << std::endl << "-------Creating a Form with target city" << RESET << std::endl;
  AForm *form3 = someRandomIntern.makeForm("shrubbery creation", "city");
  testForm(form1, form2, form3);
  delete form1;
  delete form2;
  delete form3;
}
void  testNonExistingForm(){
  std::cout << BOLD_PURPLE << std::endl << std::endl 
  << "      **TESTING NON EXISTING FORM**" << RESET << std::endl;

  std::cout << CYAN << std::endl << "-------CREATING INTERN" << RESET << std::endl;
  Intern      someRandomIntern;
  std::cout << CYAN << std::endl << "-------INTERN CREATING FORM" << RESET << std::endl;
  std::cout << GREEN << std::endl << "-------Creating a Form with target rita" << RESET << std::endl;
  AForm *form1 = someRandomIntern.makeForm("non existing form", "rita");
  std::cout << GREEN << std::endl << "-------Creating a Form with target xico" << RESET << std::endl;
  AForm *form2 = someRandomIntern.makeForm("non existing form", "xico");
  std::cout << GREEN << std::endl << "-------Creating a Form with target jenny" << RESET << std::endl;
  AForm *form3 = someRandomIntern.makeForm("non existing form", "jenny");
  testForm(form1, form2, form3);
}

bool  hasNonNumericChar(std::string str)
{
  for (std::string::const_iterator i = str.begin(); i != str.end(); ++i) {
        if (!std::isdigit(*i))
            return true;
  }
  return false;
}

bool  isNumber(std::string str){
  int i = 0;
  while(std::isspace(str[i]))
    i++;
  if(str[i] == '-' || str[i] == '+')
    i++;
  if(hasNonNumericChar(str.substr(i)))
    return false;
  return true;
}

int main()
{
  std::string input;
  try{
    std::cout << "What form should we test?" << std::endl 
    << "0: All forms\n1: Presidential Pardon Form\n2: Robotomy Request Form\n3: ShrubberyCreationForm\n4: NonExistingForm\n.:";
    std::cin >> input;
    if(!isNumber(input)){
        throw InvalidOptionException();
    }
    if(std::cin.eof())
	    exit(0);
    int option = std::atoll(input.c_str()) > 4 || std::atoll(input.c_str()) < 0 ? -1 : std::atoi(input.c_str());
    if (option == -1)
      throw InvalidOptionException();
    if(option == 1 || option == 0)
      testPresidentialPardonForm();
    if(option == 2 || option == 0)
      testRobotomyRequestForm();
    if(option == 3 || option == 0)
      testShrubberyCreationForm();
    if(option == 4 || option == 0){
      testNonExistingForm();
    }
  }
  catch (const std::exception& e) {
    std::cerr << std::endl << e.what() << std::endl << std::endl;
  }
}