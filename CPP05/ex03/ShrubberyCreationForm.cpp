#include "includes/ShrubberyCreationForm.hpp"

//Exceptions
const char* ShrubberyCreationForm::FileUnableToOpenException::what() const throw(){
    return "\033[1;31mUnable to open file\033[0m";
}

ShrubberyCreationForm::ShrubberyCreationForm()
    :   AForm("ShrubberyCreation", 145, 137), _target("default")
{
    std::cout << BOLD_PURPLE << "ShrubberyCreationForm" << RESET 
    << " default constructor called " << std::endl;
}

//target constructor
ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    :   AForm("ShrubberyCreation", 145, 137), _target(target)
{
    std::cout << BOLD_PURPLE << "ShrubberyCreationForm" << RESET 
    << " constructor called with target " << _target
    << std::endl;
}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy)
    :  AForm(copy), _target(copy._target)
{
    std::cout << BOLD_PURPLE << "ShrubberyCreationForm" << RESET 
    << " copy constructor called with target " 
    << _target << std::endl;
}

// Copy assignment operator overload
ShrubberyCreationForm& ShrubberyCreationForm::operator= (const ShrubberyCreationForm& copy) {
    // Self-assignment check
    if (this == &copy)
        return *this;
    _target = copy._target;
    this->setSigned(copy.isSigned());
    std::cout << BOLD_PURPLE << "ShrubberyCreationForm" << RESET 
    << " copy assignment operator overload called for " 
    << _target << std::endl;
    return *this;
}

//Getters:
std::string  ShrubberyCreationForm::getTarget() const {
    return _target;
}

//Getters:
void        ShrubberyCreationForm::setTarget(std::string target) {
    _target = target;
}

//Execute ShrubberyCreationForm
void        ShrubberyCreationForm::executeAction() const
{
    std::string filename = _target + "_shrubbery";
    std::ofstream file(filename.c_str());
    if (!file.is_open())
            throw FileUnableToOpenException();
    std::string asciiTree = 
    "      ccee88oo\n"
    " C8O8O8Q8PoOb o8oo\n"
    "dOB69QO8PdUOpugoO9bD\n"
    "CgggbU8OU qOp qOdoUOdcb\n"
    "     6OuU  /p u gcoUodpP\n"
    "       \\\\//  /douUP\n"
    "         \\\\\\//&/\n"
    "          |||/\\\\\n"
    "          |||\\\\/\n"
    "          |||||\n"
    "    .....//||||\\\\....\n";
    file << asciiTree;
    file.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << BOLD_PURPLE << "ShrubberyCreationForm" << RESET 
    << " destructor called" << std::endl;
}

//overload do << operator
std::ostream&       operator<<(std::ostream& out, ShrubberyCreationForm& src)
{
    out << "Name: " << src.getName() << std::endl; 
    out << "Target: " << src.getTarget() << std::endl; 
    out << "The form is signed: " << std::boolalpha << src.isSigned() << std::endl;
    out << "Grade required to sign: " << src.getGradeToSign() << std::endl;
    out << "Grade required to execute: " << src.getGradeToExecute() << std::endl;
    return(out);
}