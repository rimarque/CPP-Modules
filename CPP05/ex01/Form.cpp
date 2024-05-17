#include "includes/Form.hpp"

//Exceptions
const char* Form::GradeTooHighException::what() const throw(){
    return "\033[1;31mGrade to high!\033[0m";
}

const char* Form::GradeTooLowException::what() const throw(){
    return "\033[1;31mGrade to low!\033[0m";
}

Form::Form()
    :   _name("default"),
        _signed(false),
        _gradeToSign(75),
        _gradeToExecute(50)
{
    std::cout << BOLD_PURPLE << "Form" << RESET 
    << " default constructor called "
    << " with grade required to sign equal to " << _gradeToSign 
    << " and grade required to execute equal to " << _gradeToExecute 
    << std::endl;
}

//Name constructor
Form::Form(std::string& name)
    :   _name(name),
        _signed(false),
        _gradeToSign(75),
        _gradeToExecute(50)
{
    std::cout << BOLD_PURPLE << "Form" << RESET 
    << " default constructor called for " << _name
    << " with grade required to sign equal to " << _gradeToSign 
    << " and grade required to execute equal to " << _gradeToExecute 
    << std::endl;
}

//Atributes constructor
Form::Form(std::string& name, int gradeToSign, int gradeToExecute)
    :   _name(name),
        _signed(false),
        _gradeToSign(gradeToSign),
        _gradeToExecute(gradeToExecute)
{
    if(gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if(gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
    std::cout << BOLD_PURPLE << "Form" << RESET 
    << " atributes constructor called for " << _name 
    << " with grade required to sign equal to " << _gradeToSign 
    << " and grade required to execute equal to " << _gradeToExecute 
    << std::endl;
}

// Copy constructor
Form::Form(const Form& copy)
    :   _name(copy._name),
        _signed(copy._signed),
        _gradeToSign(copy._gradeToSign),
        _gradeToExecute(copy._gradeToExecute)
{
    std::cout << BOLD_PURPLE << "Form" << RESET 
    << " copy constructor called for " 
    << _name << std::endl;
}

// Copy assignment operator overload
Form& Form::operator= (const Form& copy) {
    // Self-assignment check
    if (this == &copy)
        return *this;
    _signed = copy._signed;
    std::cout << BOLD_PURPLE << "Form" << RESET 
    << " copy assignment operator overload called for " 
    << _name << std::endl;
    return *this;
}

//Getters:
const std::string&  Form::getName() const {
    return _name;
}

int                 Form::getGradeToSign() const {
    return _gradeToSign;
}

int                 Form::getGradeToExecute() const {
    return _gradeToExecute;
}

bool                 Form::isSigned() const {
    return _signed;
}

//Sign form
void               Form::beSigned(Bureaucrat& b)
{
    if(_signed){
        std::cout << "The form " << _name
        << " his already signed" << std::endl;
        return;
    }
    if(b.getGrade() <= _gradeToSign) {
        _signed = true;
        std::cout << "The form " << _name
        << " was signed by bureaucrat " << b.getName() << std::endl;
        return;
    }
    throw GradeTooLowException();
}

Form::~Form() {
    std::cout << BOLD_PURPLE << "Form" << RESET 
    << " destructor called" << std::endl;
}

//overload do << operator
std::ostream&       operator<<(std::ostream& out, Form& src)
{
    out << "Name: " << src.getName() << std::endl; 
    out << "The form is signed: " << std::boolalpha << src.isSigned() << std::endl;
    out << "Grade required to sign: " << src.getGradeToSign() << std::endl;
    out << "Grade required to execute: " << src.getGradeToExecute() << std::endl;
    return(out);
}
