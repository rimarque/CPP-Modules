#include "includes/Bureaucrat.hpp"
#include "includes/AForm.hpp"

//Exceptions
const char* Bureaucrat::GradeTooHighException::what() const throw(){
    return "\033[1;31mGrade to high!\033[0m";
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
    return "\033[1;31mGrade to low!\033[0m";
}

Bureaucrat::Bureaucrat()
    :   _name("default"),
        _grade(150)
{
    std::cout << BOLD_YELLOW << "Bureaucrat" << RESET 
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
    std::cout << BOLD_YELLOW << "Bureaucrat" << RESET 
    << " atributes constructor called for " << name 
    << " with grade " << grade << std::endl;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& copy)
    :   _name(copy._name),
        _grade(copy._grade)
{
    std::cout << BOLD_YELLOW << "Bureaucrat" << RESET 
    << " copy constructor called for " << _name 
    << " with grade " << _grade << std::endl;
}

// Copy assignment operator overload
//(as _name is const it's not modifiable, so it's not copyed) 
Bureaucrat& Bureaucrat::operator= (const Bureaucrat& copy) {
    // Self-assignment check
    if (this == &copy)
        return *this;
    _grade = copy._grade;
    std::cout << BOLD_YELLOW << "Bureaucrat" << RESET 
    << " copy constructor called for " << _name
    << " with grade " << _grade << std::endl;
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

void                Bureaucrat::signForm(AForm& form) const {
    try{
        form.beSigned(*this);
        std::cout << "Bureaucrat " << _name 
        << " signed form " << form.getName() << std::endl;
    }
    catch (const std::exception& e) {
            std::cerr << "Bureaucrat " << _name 
            << " couldn't sign form " << form.getName() << " because " 
            << e.what() << std::endl;
    }
}

void                Bureaucrat::executeForm(AForm const & form){
    try{
        form.executeAction(*this);
        std::cout << "Bureaucrat " << _name 
        << " executed " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
}

Bureaucrat::~Bureaucrat() {
    std::cout << BOLD_YELLOW << "Bureaucrat" << RESET 
    << " destructor called" << std::endl;
}

//overload do << operator
std::ostream&       operator<<(std::ostream& out, Bureaucrat& src)
{
    out << src.getName() << ", bureaucrat grade " << src.getGrade();
    return(out);
}