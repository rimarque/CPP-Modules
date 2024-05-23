#include "includes/PresidentialPardonForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/ShrubberyCreationForm.hpp"
#include "includes/Intern.hpp"

void  testSignForm(AForm *form1, AForm *form2, AForm *form3,
                    Bureaucrat& Executer, Bureaucrat& Signer, Bureaucrat& Failure)
{
  std::cout << CYAN << std::endl << "-------TESTING SIGNING THE FORM" << RESET << std::endl;
  std::cout << std::endl << YELLOW << "-------" << Executer.getName() << " signing form 1: " << RESET << std::endl;
  Executer.signForm(*form1);
  std::cout << std::endl << YELLOW << "-------Displaying form" << RESET << std::endl;
  std::cout << *form1 << std::endl;
  std::cout << YELLOW << "-------" << Executer.getName() << " signing form 1 (already signed): " << RESET << std::endl;
  Executer.signForm(*form1);
  std::cout << std::endl << YELLOW << "-------" << Signer.getName() << " signing form 2: " << RESET << std::endl;
  Signer.signForm(*form2);
  std::cout << std::endl << YELLOW << "-------" << Failure.getName() << " signing form 3 (grade too low): " << RESET << std::endl;
  Failure.signForm(*form3);
}

void  testExecuteForm(AForm *form1, AForm *form2, AForm *form3,
                    Bureaucrat& Executer, Bureaucrat& Signer)
{
  std::cout << CYAN << std::endl << std::endl << "-------TESTING EXECUTING THE FORM" << RESET << std::endl;
  std::cout << std::endl << YELLOW << "-------" << Executer.getName() << " executing form 1: " << RESET << std::endl;
  Executer.executeForm(*form1);
  std::cout << std::endl << YELLOW << "-------" << Signer.getName() << " executing form 2 (grade too low): " << RESET << std::endl;
  Signer.executeForm(*form2);
  std::cout << std::endl << YELLOW << "-------" << Executer.getName() << " executing form 3 (not signed): " << RESET << std::endl;
  Executer.executeForm(*form3);
}

void  testForm(AForm *form1, AForm *form2, AForm *form3)
{
  if(!form1 || !form2 || !form3)
    return ;
  std::cout << CYAN << std::endl << "-------CREATING BUREAUCRATS" << RESET << std::endl;
  std::cout << GREEN << std::endl << "-------Creating a Beaurucrat with grade to execute" << RESET << std::endl;
  Bureaucrat  Executer("Executer", form1->getGradeToExecute());
  std::cout << GREEN << std::endl << "-------Creating a Beaurucrat with grade to sign" << RESET << std::endl;
  Bureaucrat  Signer("Signer", form1->getGradeToSign());
  std::cout << GREEN << std::endl << "-------Creating a Beaurucrat with grade too low" << RESET << std::endl;
  Bureaucrat  Failure("Failure", form1->getGradeToSign() + 1);
  testSignForm(form1, form2, form3, Executer, Signer, Failure);
  testExecuteForm(form1, form2, form3, Executer, Signer);
  std::cout << std::endl;
}