#ifndef INTERN_HPP
# define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
public:
    Intern(); // Constructor
    Intern(const Intern& copy);//Copy constructor
    Intern& operator= (const Intern& copy); //Copy assignment constructor
    AForm   *makeForm(std::string name, std::string target);
    AForm   *createShrubberyCreation(std::string const &target);
	AForm	*createRobotomyRequest(std::string const &target);
	AForm	*createPresidentialPardon(std::string const &target);
    ~Intern(); // Destructor
};

#endif // INTERN_HPP
