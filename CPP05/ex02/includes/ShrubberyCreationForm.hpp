#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM__HPP

# include "AForm.hpp"

class ShrubberyCreationForm: public AForm 
{
public:
    ShrubberyCreationForm(); // Constructor
    ShrubberyCreationForm(std::string target); //Name constructor
    ShrubberyCreationForm(const ShrubberyCreationForm& copy);//Copy constructor
    ShrubberyCreationForm& operator= (const ShrubberyCreationForm& copy); //Copy assignment constructor
    //Getters:
    std::string getTarget() const;
    //Setters:
    void        setTarget(std::string);
    //My methods:
    void        executeAction(const Bureaucrat& executer) const;
    ~ShrubberyCreationForm(); // Destructor

private:
    std::string   _target;
};

#endif // FORM_H