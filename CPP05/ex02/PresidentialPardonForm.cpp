#include "includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    :   AForm("ShrubberyCreation", 25, 5), _target("default")
{
    std::cout << BOLD_PURPLE << "PresidentialPardonForm" << RESET 
    << " default constructor called "
    << " with grade required to sign equal to " << this->getGradeToSign() 
    << " and grade required to execute equal to " << this->getGradeToSign() 
    << std::endl;
}

//target constructor
PresidentialPardonForm::PresidentialPardonForm(std::string target)
    :   AForm("ShrubberyCreation", 25, 5), _target(target)
{
    std::cout << BOLD_PURPLE << "PresidentialPardonForm" << RESET 
    << " target constructor called for " << _target
    << " with grade required to sign equal to " << this->getGradeToSign()
    << " and grade required to execute equal to " << this->getGradeToExecute()
    << std::endl;
}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy)
    :  AForm(copy), _target(copy._target)
{
    std::cout << BOLD_PURPLE << "PresidentialPardonForm" << RESET 
    << " copy constructor called for " 
    << _target << std::endl;
}

// Copy assignment operator overload
PresidentialPardonForm& PresidentialPardonForm::operator= (const PresidentialPardonForm& copy) {
    // Self-assignment check
    if (this == &copy)
        return *this;
    _target = copy._target;
    this->setSigned(copy.isSigned());
    std::cout << BOLD_PURPLE << "PresidentialPardonForm" << RESET 
    << " copy assignment operator overload called for " 
    << _target << std::endl;
    return *this;
}

//Getters:
std::string  PresidentialPardonForm::getTarget() const {
    return _target;
}

//Getters:
void        PresidentialPardonForm::setTarget(std::string target) {
    _target = target;
}

//Execute PresidentialPardonForm
void        PresidentialPardonForm::executeAction(const Bureaucrat& executer) const
{
    try{
        this->execute(executer);
    }
    catch(const std::exception& e){
        std::cerr << e.what() << std::endl;
    }
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << BOLD_PURPLE << "PresidentialPardonForm" << RESET 
    << " destructor called" << std::endl;
}

//overload do << operator
std::ostream&       operator<<(std::ostream& out, PresidentialPardonForm& src)
{
    out << "Target: " << src.getTarget() << std::endl; 
    out << "The form is signed: " << std::boolalpha << src.isSigned() << std::endl;
    out << "Grade required to sign: " << src.getGradeToSign() << std::endl;
    out << "Grade required to execute: " << src.getGradeToExecute() << std::endl;
    return(out);
}