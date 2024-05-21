#include "includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    :   _target("default"),
        _signed(false),
        _gradeToSign(75),
        _gradeToExecute(50)
{
    std::cout << BOLD_PURPLE << "ShrubberyCreationForm" << RESET 
    << " default constructor called "
    << " with grade required to sign equal to " << _gradeToSign 
    << " and grade required to execute equal to " << _gradeToExecute 
    << std::endl;
}

//target constructor
ShrubberyCreationForm::ShrubberyCreationForm(std::string& target)
    :   _target(target),
        _signed(false),
        _gradeToSign(75),
        _gradeToExecute(50)
{
    std::cout << BOLD_PURPLE << "ShrubberyCreationForm" << RESET 
    << " default constructor called for " << _target
    << " with grade required to sign equal to " << _gradeToSign 
    << " and grade required to execute equal to " << _gradeToExecute 
    << std::endl;
}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy)
    :   _target(copy._target),
        _signed(copy._signed),
        _gradeToSign(copy._gradeToSign),
        _gradeToExecute(copy._gradeToExecute)
{
    std::cout << BOLD_PURPLE << "ShrubberyCreationForm" << RESET 
    << " copy constructor called for " 
    << _target << std::endl;
}

// Copy assignment operator overload
ShrubberyCreationForm& ShrubberyCreationForm::operator= (const ShrubberyCreationForm& copy) {
    // Self-assignment check
    if (this == &copy)
        return *this;
    _signed = copy._signed;
    std::cout << BOLD_PURPLE << "ShrubberyCreationForm" << RESET 
    << " copy assignment operator overload called for " 
    << _target << std::endl;
    return *this;
}

//Getters:
const std::string&  ShrubberyCreationForm::getTarget() const {
    return _target;
}

const int             ShrubberyCreationForm::getGradeToSign() const {
    return _gradeToSign;
}

const int            ShrubberyCreationForm::getGradeToExecute() const {
    return _gradeToExecute;
}

bool                 ShrubberyCreationForm::isSigned() const {
    return _signed;
}

//Sign ShrubberyCreationForm
void               ShrubberyCreationForm::beSigned(const Bureaucrat& b)
{
    if(_signed)
        throw FormIsSignedException();
    if(b.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _signed = true;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << BOLD_PURPLE << "ShrubberyCreationForm" << RESET 
    << " destructor called" << std::endl;
}

//overload do << operator
std::ostream&       operator<<(std::ostream& out, Form& src)
{
    out << "target: " << src.getTarget() << std::endl; 
    out << "The form is signed: " << std::boolalpha << src.isSigned() << std::endl;
    out << "Grade required to sign: " << src.getGradeToSign() << std::endl;
    out << "Grade required to execute: " << src.getGradeToExecute() << std::endl;
    return(out);
}