#include "includes/PresidentialPardonForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/ShrubberyCreationForm.hpp"

void    testPresidentialPardonForm()
{
  std::cout << BOLD_PURPLE << std::endl << "      **Testing Presidential Pardon Form**" << RESET << std::endl;

  std::cout << GREEN << std::endl << "-------Creating a form" << RESET << std::endl;
  PresidentialPardonForm  a("rita");
  std::cout << GREEN << std::endl << "-------Creating a copy of the form, using copy constructor" << RESET << std::endl;
  PresidentialPardonForm copy1(a);
  std::cout << GREEN << std::endl << "-------Creating a form, using default constructor" << RESET << std::endl;
  PresidentialPardonForm copy2;
  
  std::cout << std::endl << CYAN << "-------Displaying form" << RESET << std::endl;
  std::cout << a << std::endl;
  std::cout << std::endl << CYAN << "-------Testing copy constructor" << RESET << std::endl;
  std::cout << copy1 << std::endl;
  std::cout << std::endl << CYAN << "-------Testing default constructor" << RESET << std::endl;
  std::cout << copy2 << std::endl;

  std::cout << PURPLE << std::endl << "      **Testing signing the form**" << RESET << std::endl;
  std::cout << GREEN << std::endl << "-------Creating a Beaurucrat with grade to execute" << RESET << std::endl;
  Bureaucrat  Executer("Executer", 5);
  std::cout << std::endl << CYAN << "-------" << Executer.getName() << " signing form a: " << RESET << std::endl;
  Executer.signForm(a);
  std::cout << std::endl << CYAN << "-------Displaying form a" << RESET << std::endl;
  std::cout << a << std::endl;

  std::cout << std::endl << CYAN << "-------" << Executer.getName() << " signing form a (already signed): " << RESET << std::endl;
  Executer.signForm(a);

  std::cout << GREEN << std::endl << "-------Creating a Beaurucrat with grade to sign" << RESET << std::endl;
  Bureaucrat  Signer("Signer", 25);
  std::cout << std::endl << CYAN << "-------" << Signer.getName() << " signing form copy1: " << RESET << std::endl;
  Signer.signForm(copy1);

  std::cout << GREEN << std::endl << "-------Creating a Beaurucrat with grade too low" << RESET << std::endl;
  Bureaucrat  Failure("Failure", 50);
  std::cout << std::endl << CYAN << "-------" << Failure.getName() << " signing form copy2 (grade too low): " << RESET << std::endl;
  Failure.signForm(copy2);

  std::cout << PURPLE << std::endl << "      **Testing executing the form**" << RESET << std::endl;
  std::cout << std::endl << CYAN << "-------" << Executer.getName() << " executing form a: " << RESET << std::endl;
  Executer.executeForm(a);
  std::cout << std::endl << CYAN << "-------" << Signer.getName() << " executing form copy1 (grade too low): " << RESET << std::endl;
  Signer.executeForm(copy1);
  std::cout << std::endl << CYAN << "-------" << Executer.getName() << " executing form copy2 (not signed): " << RESET << std::endl;
  Executer.executeForm(copy2);

  std::cout << std::endl << CYAN << "-------Testing copy assigment operator (copying form a to default)" 
  << std::endl << "[only copies bool signed and target, because other atributes are constant]" << RESET << std::endl;
  copy2 = a;
  std::cout << copy2 << std::endl;
}

int main()
{
  try{
    testPresidentialPardonForm();
    //void  testRobotomyRequestForm();
    //void  testShrubberyCreationForm();
  }
  catch (const std::exception& e) {
    std::cerr << std::endl << e.what() << std::endl << std::endl;
  }
}