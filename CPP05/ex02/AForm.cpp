#include "includes/AForm.hpp"

//Exceptions
const char* AForm::GradeTooHighException::what() const throw(){
    return "\033[1;31mGrade to high!\033[0m";
}

const char* AForm::GradeTooLowException::what() const throw(){
    return "\033[1;31mGrade to low!\033[0m";
}

const char* AForm::FormIsSignedException::what() const throw(){
    return "\033[1;31mForm already signed!\033[0m";
}

const char* AForm::FormNotSignedException::what() const throw(){
    return "\033[1;31mForm not signed!\033[0m";
}

AForm::AForm()
    :   _name("default"),
        _signed(false),
        _gradeToSign(75),
        _gradeToExecute(50)
{
    std::cout << BOLD_PURPLE << "AForm" << RESET 
    << " default constructor called "
    << " with grade required to sign equal to " << _gradeToSign 
    << " and grade required to execute equal to " << _gradeToExecute 
    << std::endl;
}

//Name constructor
AForm::AForm(std::string& name)
    :   _name(name),
        _signed(false),
        _gradeToSign(75),
        _gradeToExecute(50)
{
    std::cout << BOLD_PURPLE << "AForm" << RESET 
    << " default constructor called for " << _name
    << " with grade required to sign equal to " << _gradeToSign 
    << " and grade required to execute equal to " << _gradeToExecute 
    << std::endl;
}

//Atributes constructor
AForm::AForm(std::string name, int gradeToSign, int gradeToExecute)
    :   _name(name),
        _signed(false),
        _gradeToSign(gradeToSign),
        _gradeToExecute(gradeToExecute)
{
    if(gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if(gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
    std::cout << BOLD_PURPLE << "AForm" << RESET 
    << " atributes constructor called for " << _name 
    << " with grade required to sign equal to " << _gradeToSign 
    << " and grade required to execute equal to " << _gradeToExecute 
    << std::endl;
}

// Copy constructor
AForm::AForm(const AForm& copy)
    :   _name(copy._name),
        _signed(copy._signed),
        _gradeToSign(copy._gradeToSign),
        _gradeToExecute(copy._gradeToExecute)
{
    std::cout << BOLD_PURPLE << "AForm" << RESET 
    << " copy constructor called for " 
    << _name << std::endl;
}

// Copy assignment operator overload
AForm& AForm::operator= (const AForm& copy) {
    // Self-assignment check
    if (this == &copy)
        return *this;
    _signed = copy._signed;
    std::cout << BOLD_PURPLE << "AForm" << RESET 
    << " copy assignment operator overload called for " 
    << _name << std::endl;
    return *this;
}

//Getters:
const std::string&  AForm::getName() const {
    return _name;
}

const int             AForm::getGradeToSign() const {
    return _gradeToSign;
}

const int            AForm::getGradeToExecute() const {
    return _gradeToExecute;
}

bool                 AForm::isSigned() const {
    return _signed;
}

//Setters
void                AForm::setSigned(bool s){
    _signed = s;
}

//Sign AForm
void               AForm::beSigned(const Bureaucrat& b)
{
    if(_signed)
        throw FormIsSignedException();
    if(b.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _signed = true;
}


/* You have to check that the form is signed and that the grade of the bureaucrat
attempting to execute the form is high enough. */
void                AForm::execute(Bureaucrat const& executor) const
{
    if(!_signed)
        throw FormNotSignedException();
    if(executor.getGrade() > _gradeToExecute)
        throw GradeTooLowException();
}

AForm::~AForm() {
    std::cout << BOLD_PURPLE << "AForm" << RESET 
    << " destructor called" << std::endl;
}

//overload do << operator
std::ostream&       operator<<(std::ostream& out, AForm& src)
{
    out << "Name: " << src.getName() << std::endl; 
    out << "The form is signed: " << std::boolalpha << src.isSigned() << std::endl;
    out << "Grade required to sign: " << src.getGradeToSign() << std::endl;
    out << "Grade required to execute: " << src.getGradeToExecute() << std::endl;
    return(out);
}