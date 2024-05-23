#ifndef PRESIDENCIALPARDONFORM_HPP
# define PRESIDENCIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm: public AForm 
{
public:
    PresidentialPardonForm(); // Constructor
    PresidentialPardonForm(std::string target); //Name constructor
    PresidentialPardonForm(const PresidentialPardonForm& copy);//Copy constructor
    PresidentialPardonForm& operator= (const PresidentialPardonForm& copy); //Copy assignment op
    //Getters:
    std::string getTarget() const;
    //Setters:
    void        setTarget(std::string);
    //My methods:
    void        executeAction(const Bureaucrat& executer) const;
    ~PresidentialPardonForm(); // Destructor

private:
    std::string   _target;
};

std::ostream&       operator<<(std::ostream& out, PresidentialPardonForm& src);

#endif // FORM_H