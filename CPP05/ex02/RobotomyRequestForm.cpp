#include "includes/RobotomyRequestForm.hpp"

//Exceptions
const char* RobotomyRequestForm::RobotomyFailedException::what() const throw(){
    return "\033[1;31mRobotomy failed!\033[0m";
}

RobotomyRequestForm::RobotomyRequestForm()
    :   AForm("ShrubberyCreation", 72, 45), _target("default")
{
    std::cout << BOLD_PURPLE << "RobotomyRequestForm" << RESET 
    << " default constructor called "
    << " with grade required to sign equal to " << this->getGradeToSign() 
    << " and grade required to execute equal to " << this->getGradeToSign() 
    << std::endl;
}

//target constructor
RobotomyRequestForm::RobotomyRequestForm(std::string target)
    :   AForm("ShrubberyCreation", 72, 45), _target(target)
{
    std::cout << BOLD_PURPLE << "RobotomyRequestForm" << RESET 
    << " target constructor called for " << _target
    << " with grade required to sign equal to " << this->getGradeToSign()
    << " and grade required to execute equal to " << this->getGradeToExecute()
    << std::endl;
}

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy)
    :  AForm(copy), _target(copy._target)
{
    std::cout << BOLD_PURPLE << "RobotomyRequestForm" << RESET 
    << " copy constructor called for " 
    << _target << std::endl;
}

// Copy assignment operator overload
RobotomyRequestForm& RobotomyRequestForm::operator= (const RobotomyRequestForm& copy) {
    // Self-assignment check
    if (this == &copy)
        return *this;
    _target = copy._target;
    this->setSigned(copy.isSigned());
    std::cout << BOLD_PURPLE << "RobotomyRequestForm" << RESET 
    << " copy assignment operator overload called for " 
    << _target << std::endl;
    return *this;
}

//Getters:
std::string  RobotomyRequestForm::getTarget() const {
    return _target;
}

//Getters:
void        RobotomyRequestForm::setTarget(std::string target) {
    _target = target;
}

//Execute RobotomyRequestForm
void        RobotomyRequestForm::executeAction(const Bureaucrat& executer) const
{
    try{
        this->execute(executer);
        std::cout << "Drilling noises...\n";
        std::srand((unsigned int)(std::time(0)));
        bool success = rand() % 2;
        if (!success)
            throw RobotomyFailedException();
        std::cout << _target << " has been robotomized successfully" << std::endl;
    }
    catch(const std::exception& e){
        std::cerr << e.what() << std::endl;
    }
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << BOLD_PURPLE << "RobotomyRequestForm" << RESET 
    << " destructor called" << std::endl;
}

//overload do << operator
std::ostream&       operator<<(std::ostream& out, RobotomyRequestForm& src)
{
    out << "Target: " << src.getTarget() << std::endl; 
    out << "The form is signed: " << std::boolalpha << src.isSigned() << std::endl;
    out << "Grade required to sign: " << src.getGradeToSign() << std::endl;
    out << "Grade required to execute: " << src.getGradeToExecute() << std::endl;
    return(out);
}