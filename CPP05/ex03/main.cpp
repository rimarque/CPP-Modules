#include "includes/PresidentialPardonForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/ShrubberyCreationForm.hpp"
#include "includes/InvalidOptionException.hpp"
#include "includes/Intern.hpp"

void    testPresidentialPardonForm()
{
  std::cout << BOLD_PURPLE << std::endl << std::endl 
  << "      **TESTING PRESIDENCIAL PARDON FORM**" << RESET << std::endl;

  std::cout << CYAN << std::endl << "-------CREATING INTERN" << RESET << std::endl;
  Intern  someRandomIntern;
  std::cout << CYAN << std::endl << "-------INTERN CREATING FORMS" << RESET << std::endl;
  AForm *form1 = someRandomIntern.makeForm("presidential pardon", "rita");
  AForm *form2 = someRandomIntern.makeForm("presidential pardon", "xico");
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
  AForm *form1 = someRandomIntern.makeForm("robotomy request", "rita");
  AForm *form2 = someRandomIntern.makeForm("robotomy request", "xico");
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
  AForm *form1 = someRandomIntern.makeForm("shrubbery creation", "rita");
  AForm *form2 = someRandomIntern.makeForm("shrubbery creation", "xico");
  AForm *form3 = someRandomIntern.makeForm("shrubbery creation", "jenny");
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
  AForm *form1 = someRandomIntern.makeForm("non existing form", "rita");
  AForm *form2 = someRandomIntern.makeForm("non existing form", "xico");
  AForm *form3 = someRandomIntern.makeForm("non existing form", "jenny");
  testForm(form1, form2, form3);
}

int main()
{
  std::string input;
  try{
    std::cout << "What form should we test?" << std::endl 
    << "1: Presidential Pardon Form\n2: Robotomy Request Form\n3: ShrubberyCreationForm\n4: NonExistingForm\n5: All forms\n.:";
    std::cin >> input;
    if(std::cin.eof())
	    exit(0);
    int option = std::atoll(input.c_str()) > 5 || std::atoll(input.c_str()) < 1 ? -1 : std::atoi(input.c_str());
    if (option == -1)
      throw InvalidOptionException();
    if(option == 1 || option == 5)
      testPresidentialPardonForm();
    if(option == 2 || option == 5)
      testRobotomyRequestForm();
    if(option == 3 || option == 5)
      testShrubberyCreationForm();
    if(option == 4 || option == 5){
      testNonExistingForm();
    }
  }
  catch (const std::exception& e) {
    std::cerr << std::endl << e.what() << std::endl << std::endl;
  }
}