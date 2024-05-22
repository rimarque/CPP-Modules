#include "includes/ShrubberyCreationForm.hpp"

//Exceptions
const char* ShrubberyCreationForm::FileUnableToOpenException::what(std::string filename) const throw(){
    std::string result = "\033[1;31mUnable to open file ";
    result.append(filename);
    return result.c_str();
}

ShrubberyCreationForm::ShrubberyCreationForm()
    :   AForm("ShrubberyCreation", 245, 137), _target("default")
{
    std::cout << BOLD_PURPLE << "ShrubberyCreationForm" << RESET 
    << " default constructor called "
    << " with grade required to sign equal to " << this->getGradeToSign() 
    << " and grade required to execute equal to " << this->getGradeToSign() 
    << std::endl;
}

//target constructor
ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    :   AForm("ShrubberyCreation", 245, 137), _target(target)
{
    std::cout << BOLD_PURPLE << "ShrubberyCreationForm" << RESET 
    << " target constructor called for " << _target
    << " with grade required to sign equal to " << this->getGradeToSign()
    << " and grade required to execute equal to " << this->getGradeToExecute()
    << std::endl;
}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy)
    :  AForm(copy), _target(copy._target)
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
void        ShrubberyCreationForm::executeAction(const Bureaucrat& executer) const
{
    try{
        this->execute(executer);
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
    catch(const std::exception& e){
        std::cerr << e.what() << RESET << std::endl;
    }
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << BOLD_PURPLE << "ShrubberyCreationForm" << RESET 
    << " destructor called" << std::endl;
}

//overload do << operator
std::ostream&       operator<<(std::ostream& out, ShrubberyCreationForm& src)
{
    out << "Target: " << src.getTarget() << std::endl; 
    out << "The form is signed: " << std::boolalpha << src.isSigned() << std::endl;
    out << "Grade required to sign: " << src.getGradeToSign() << std::endl;
    out << "Grade required to execute: " << src.getGradeToExecute() << std::endl;
    return(out);
}