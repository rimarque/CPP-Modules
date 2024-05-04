#include "includes/Bureaucrat.hpp"
//Exceptions

const char* Bureaucrat::GradeTooHighException::what() const throw(){
    return "Grade to high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
    return "Grade to low!";
}

Bureaucrat::Bureaucrat()
    :   _name("default"),
        _grade(150)
{
    std::cout << BOLD_WHITE << "Bureaucrat" << RESET 
    << " default constructor called" << std::endl;
}

//atributes constructor
Bureaucrat::Bureaucrat(std::string name, int grade)
    :   _name(name)
{
    if(grade < 1)
        throw GradeTooHighException();
    if(grade > 150)
        throw GradeTooLowException();
    _grade = grade;
    std::cout << BOLD_WHITE << "Bureaucrat" << RESET 
    << " atributes constructor called for " << name 
    << " with grade " << grade << std::endl;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& copy)
    :   _name(copy._name),
        _grade(copy._grade)
{
    std::cout << BOLD_WHITE << "Bureaucrat" << RESET 
    << " copy constructor called" << std::endl;
}

// Copy assignment operator overload
Bureaucrat& Bureaucrat::operator= (const Bureaucrat& copy) {
    // Self-assignment check
    if (this == &copy)
        return *this;
    _grade = copy._grade;
    std::cout << BOLD_WHITE << "Bureaucrat" << RESET 
    << " copy assignment operator overload" << std::endl;
    return *this;
}

//Getters:
const std::string&  Bureaucrat::getName() const {
    return _name;
}

int                 Bureaucrat::getGrade() const {
    return _grade;
}

//Increment/decrement grade
void                Bureaucrat::incrementGrade() {
    
    if(_grade < 2)
        throw GradeTooHighException();
    _grade--;
}

void                Bureaucrat::decrementGrade() {
    if(_grade > 149)
        throw GradeTooLowException();
    _grade++;
}


Bureaucrat::~Bureaucrat() {
    std::cout << BOLD_WHITE << "Bureaucrat" << RESET 
    << " destructor called" << std::endl;
}

//overload do << operator
std::ostream&       operator<<(std::ostream& out, Bureaucrat src)
{
    out << src.getName() << " bureaucrat grade " << src.getGrade();
    return(out);
}