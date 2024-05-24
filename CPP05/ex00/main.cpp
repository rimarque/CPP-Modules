#include "includes/Bureaucrat.hpp"

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

void    set_input(std::string *name, std::string *input, int *grade, int *rounds){
    std::cout << "What should be the name of our Bureaucrat?" << std::endl;
    std::getline(std::cin, *name);
    if(std::cin.eof())
		exit(0);
    std::cout << "What should be their grade?" << std::endl << "Valid grades range from 150 (lowest) to 1 (highest),"
    << " feel free to test with invalid grades!" << std::endl;
    std::cin >> *input;
    if(std::cin.eof())
		exit(0);
    if(!isNumber(*input)){
        std::cerr << RED << "Not a number!" << RESET << std::endl;
        exit(1);
    }
    *grade = std::atoi(input->c_str());
    std::cout << "To test the incresing and decresing of the Bureaucrat's grades, let's make a loop. " 
    << "How many rounds of tests would you like to do?" << std::endl << "Pick a number between 1 and 150" << std::endl;
    std::cin >> *input;
    if(!isNumber(*input)){
        std::cerr << RED << "Not a number!" << RESET << std::endl;
        exit(1);
    }
    if(std::cin.eof())
		exit(0);
    *rounds = std::atoi(input->c_str());
    if (*rounds < 1 || *rounds > 150){
        std::cerr << RED << "error: number out of range" << RESET << std::endl;
        exit(1);
    }
    std::cout << GREEN << "Thanks for the info! Are you ready for testing?" << std::endl 
    << "(press y for yes, anyting else will make you exit the program)" << RESET << std::endl;
    std::cin >> *input;
    if(std::cin.eof())
		exit(0);
}

void    testing_const_copy(Bureaucrat& a, Bureaucrat& b, Bureaucrat& c)
{
    std::cout << std::endl << CYAN << "a: -------Testing atributes constructor" << RESET << std::endl;
    std::cout << a << std::endl;
    std::cout << std::endl << CYAN << "b: -------Testing copy constructor" << RESET << std::endl;
    std::cout << b << std::endl;
    std::cout << std::endl << CYAN << "c: -------Testing default constructor" << RESET << std::endl;
    std::cout << c << std::endl;
    std::cout << std::endl << CYAN << "c: -------Testing copy assigment operator (coping b to c)" << RESET << std::endl;
    c = b;
    std::cout << c << std::endl;
}

void    testing_inc_dec(Bureaucrat& a, Bureaucrat& b, Bureaucrat& c, int n) {
    std::cout << std::endl << "-------" << GREEN << "Incrementing a and c" << RESET "," 
    << RED << " decrementing b" << RESET <<":"<< std::endl;
    for(int i = 0; i < n; i++) {
        std::cout << std::endl << BOLD_CYAN << "ROUND " << i + 1 << RESET << std::endl;
        a.incrementGrade();
        b.decrementGrade();
        c.incrementGrade();
        std::cout << GREEN << "a:" << RESET << std::endl;
        std::cout << a << std::endl;
        std::cout << RED << "b:" << RESET << std::endl;
        std::cout << b << std::endl;
        std::cout << GREEN << "c:" << RESET << std::endl;
        std::cout << c << std::endl;
    }
}

int main()
{
    std::string name;
    std::string input;
    int         grade;
    int         rounds;

    set_input(&name, &input, &grade, &rounds);
    if(!input.compare("y"))
    {
        try{
            std::cout << GREEN << std::endl << "-------Creating Bureaucrat a, using atributes constructor" << RESET << std::endl;
            Bureaucrat a(name, grade);
            std::cout << GREEN << std::endl << "-------Creating Bureaucrat b, using copy constructor" << RESET << std::endl;
            Bureaucrat  b(a);
            std::cout << GREEN << std::endl << "-------Creating Bureaucrat c, using default constructor" << RESET << std::endl;
            Bureaucrat  c;
            testing_const_copy(a, b, c);
            testing_inc_dec(a, b, c, rounds);
        }
        catch (const std::exception& e) {
            std::cerr << std::endl << e.what() << std::endl << std::endl;
        }
    }
    return(0);
}