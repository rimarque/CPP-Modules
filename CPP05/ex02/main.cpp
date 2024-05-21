#include "includes/Form.hpp"

void    set_input(std::string *bName, std::string *fName, int *bGrade, int *fGradeSign, int *fGradeExec){
    std::string input;

    std::cout << "What should be the name of our Bureaucrat?" << std::endl;
    std::getline(std::cin, *bName);
    if(std::cin.eof())
		exit(0);
    std::cout << "What should be their grade?" << std::endl << "Valid grades range from 150 (lowest) to 1 (highest),"
    << " feel free to test with invalid grades!" << std::endl;
    std::cin >> input;
    if(std::cin.eof())
		exit(0);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    *bGrade = std::atoi(input.c_str());
    std::cout << "Lets create a form! What should be it's name?" << std::endl;
    std::getline(std::cin, *fName);
    if(std::cin.eof())
		exit(0);
    std::cout << "What should be the grade required to sign the form?" << std::endl << "Valid grades range from 150 (lowest) to 1 (highest),"
    << " feel free to test with invalid grades!" << std::endl;
    std::cin >> input;
    if(std::cin.eof())
		exit(0);
    *fGradeSign = std::atoi(input.c_str());
    std::cout << "What should be the grade required to execute the form?" << std::endl << "Valid grades range from 150 (lowest) to 1 (highest),"
    << " feel free to test with invalid grades!" << std::endl;
    std::cin >> input;
    if(std::cin.eof())
		exit(0);
    *fGradeExec = std::atoi(input.c_str());
    std::cout << GREEN << "Thanks for the info! Are you ready for testing?" << std::endl 
    << "(press y for yes, anyting else will make you exit the program)" << RESET << std::endl;
    std::cin >> input;
    if(std::cin.eof())
		exit(0);
    std::system("clear");
}

void    testForm(Bureaucrat& bure, Form& form)
{
  std::string rita = "rita";

  std::cout << GREEN << std::endl << "-------Creating a copy of the form, using copy constructor" << RESET << std::endl;
  Form    copy1(form);
  std::cout << GREEN << std::endl << "-------Creating a form, using default constructor" << RESET << std::endl;
  Form    copy2;
  std::cout << std::endl << CYAN << "-------Testing atributes constructor" << RESET << std::endl;
  std::cout << form << std::endl;
  std::cout << std::endl << CYAN << "-------Testing copy constructor" << RESET << std::endl;
  std::cout << copy1 << std::endl;
  std::cout << std::endl << CYAN << "-------Testing default constructor" << RESET << std::endl;
  std::cout << copy2 << std::endl;
  std::cout << std::endl << CYAN << "-------Testing sign form: " << RESET << std::endl;
  bure.signForm(form);
  std::cout << std::endl << CYAN << "-------Displaying form" << RESET << std::endl;
  std::cout << form << std::endl;
  std::cout << std::endl << CYAN << "-------Testing copy assigment operator (copying form to default)" 
  << std::endl << "[only copies bool signed, because other atributes are constant]" << RESET << std::endl;
  copy2 = form;
  std::cout << copy2 << std::endl;
  std::cout << std::endl << CYAN << "-------Testing sign form: " << RESET << std::endl;
  bure.signForm(form);
}

int main()
{
  std::string bName;
  std::string fName;
  int         bGrade;
  int         fGradeSign;
  int         fGradeExec;

  set_input(&bName, &fName, &bGrade, &fGradeSign, &fGradeExec);
  try{
    std::cout << GREEN << std::endl << "-------Creating a Bureaucrat, using atributes constructor" << RESET << std::endl;
    Bureaucrat bure(bName, bGrade);
    std::cout << GREEN << std::endl << "-------Creating a Form, using atributes constructor" << RESET << std::endl;
    Form       form(fName, fGradeSign, fGradeExec);
    testForm(bure, form);
  }
  catch (const std::exception& e) {
    std::cerr << std::endl << e.what() << std::endl << std::endl;
  }
}