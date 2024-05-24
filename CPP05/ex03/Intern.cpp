#include "includes/Intern.hpp"
#include "includes/InvalidException.hpp"

Intern::Intern() {
    std::cout << BOLD_WHITE << "Intern" << RESET 
    << " default constructor called" << std::endl;
}

// Copy constructor
Intern::Intern(const Intern& copy) {
    *this = copy;
    std::cout << BOLD_WHITE << "Intern" << RESET 
    << " copy constructor called" << std::endl;
}

// Copy assignment operator overload
Intern& Intern::operator= (const Intern& copy) {
    // Self-assignment check
    if (this == &copy)
        return *this;
    std::cout << BOLD_WHITE << "Intern" << RESET 
    << " copy assignment operator overload" << std::endl;
    return *this;
}

AForm*	Intern::createShrubberyCreation(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

AForm*	Intern::createRobotomyRequest(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

AForm*	Intern::createPresidentialPardon(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

AForm*    Intern::makeForm(std::string name, std::string target) {
    std::string forms[3] ={"presidential pardon", "robotomy request", "shrubbery creation"};
    AForm* (Intern::*p[])(const std::string&) = {&Intern::createPresidentialPardon, &Intern::createRobotomyRequest, &Intern::createShrubberyCreation};
    AForm   *form = NULL;
    try
    {
        for (int i = 0; i < 3; i++) {
            if(!forms[i].compare(name)){
                form = (this->*p[i])(target);
                std::cout << "Intern creates form " << name << std::endl;
                return(form);
            }
        }
        throw InvalidFormException();
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return(form);
}

Intern::~Intern() {
    std::cout << BOLD_WHITE << "Intern" << RESET 
    << " destructor called" << std::endl;
}
