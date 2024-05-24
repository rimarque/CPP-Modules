#include "includes/PresidentialPardonForm.hpp"

void  testSignForm(PresidentialPardonForm& targetForm, PresidentialPardonForm& defaultForm, PresidentialPardonForm& copiedForm,
                    Bureaucrat& Executer, Bureaucrat& Signer, Bureaucrat& Failure)
{
  std::cout << CYAN << std::endl << "-------TESTING SIGNING THE FORM" << RESET << std::endl;
  std::cout << std::endl << YELLOW << "-------" << Executer.getName() << " signing form: " << RESET << std::endl;
  Executer.signForm(targetForm);
  std::cout << std::endl << YELLOW << "-------Displaying form" << RESET << std::endl;
  std::cout << targetForm << std::endl;
  std::cout << YELLOW << "-------" << Executer.getName() << " signing form (already signed): " << RESET << std::endl;
  Executer.signForm(targetForm);
  std::cout << std::endl << YELLOW << "-------" << Signer.getName() << " signing copied form: " << RESET << std::endl;
  Signer.signForm(copiedForm);
  std::cout << std::endl << YELLOW << "-------" << Failure.getName() << " signing default form (grade too low): " << RESET << std::endl;
  Failure.signForm(defaultForm);
}

void  testExecuteForm(PresidentialPardonForm& targetForm, PresidentialPardonForm& defaultForm, PresidentialPardonForm& copiedForm,
                    Bureaucrat& Executer, Bureaucrat& Signer)
{
  std::cout << CYAN << std::endl << std::endl << "-------TESTING EXECUTING THE FORM" << RESET << std::endl;
  std::cout << std::endl << YELLOW << "-------" << Executer.getName() << " executing form: " << RESET << std::endl;
  Executer.executeForm(targetForm);
  std::cout << std::endl << YELLOW << "-------" << Signer.getName() << " executing copied form (grade too low): " << RESET << std::endl;
  Signer.executeForm(copiedForm);
  std::cout << std::endl << YELLOW << "-------" << Executer.getName() << " executing default form (not signed): " << RESET << std::endl;
  Executer.executeForm(defaultForm);
}

void  testForm(PresidentialPardonForm& targetForm, PresidentialPardonForm& defaultForm, PresidentialPardonForm& copiedForm)
{
  std::cout << CYAN << std::endl << "-------CREATING BUREAUCRATS" << RESET << std::endl;
  std::cout << GREEN << std::endl << "-------Creating a Beaurucrat with grade to execute" << RESET << std::endl;
  Bureaucrat  Executer("Executer", 5);
  std::cout << GREEN << std::endl << "-------Creating a Beaurucrat with grade to sign" << RESET << std::endl;
  Bureaucrat  Signer("Signer", 25);
  std::cout << GREEN << std::endl << "-------Creating a Beaurucrat with grade too low" << RESET << std::endl;
  Bureaucrat  Failure("Failure", 50);
  testSignForm(targetForm, defaultForm, copiedForm, Executer, Signer, Failure);
  testExecuteForm(targetForm, defaultForm, copiedForm, Executer, Signer);
  std::cout << std::endl;
}

void    testPresidentialPardonForm()
{
  std::cout << BOLD_PURPLE << std::endl << std::endl 
  << "      **TESTING PRESIDENCIAL PARDON FORM**" << RESET << std::endl;

  std::cout << CYAN << std::endl << "-------CREATING FORMS" << RESET << std::endl;
  std::cout << GREEN << std::endl << "-------Creating a form, using target constructor" << RESET << std::endl;
  PresidentialPardonForm  targetForm("Rita");
  std::cout << GREEN << std::endl << "-------Creating a form, using default constructor" << RESET << std::endl;
  PresidentialPardonForm defaultForm;
  std::cout << GREEN << std::endl << "-------Creating a copy of the form, using copy constructor" << RESET << std::endl;
  PresidentialPardonForm copiedForm(targetForm);
  
  std::cout << std::endl << YELLOW << "-------Displaying form" << RESET << std::endl;
  std::cout << targetForm << std::endl;
  std::cout << YELLOW << "-------Displaying default form" << RESET << std::endl;
  std::cout << defaultForm << std::endl;

  std::cout << CYAN << std::endl << "-------TESTING COPY CONSTRUCTOR" << RESET << std::endl;
  std::cout << std::endl << YELLOW << "-------Displaying copied form" << RESET << std::endl;
  std::cout << copiedForm << std::endl;

  testForm(targetForm, defaultForm, copiedForm);

  std::cout << CYAN << std::endl << std::endl << "-------TESTING COPY ASSIGMENT OPERATOR" << RESET << std::endl;
  std::cout << std::endl << YELLOW << "-------Copying form to Default" << RESET << std::endl;
  defaultForm = targetForm;
  std::cout << std::endl << YELLOW << "-------Displaying copied form" << RESET << std::endl;
  std::cout << defaultForm << std::endl;
}