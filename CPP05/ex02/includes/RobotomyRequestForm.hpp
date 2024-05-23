#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM__HPP

# include "AForm.hpp"

class RobotomyRequestForm: public AForm 
{
public:
    class RobotomyFailedException: public std::exception {
        public:
            virtual const char* what() const throw();
    };
    RobotomyRequestForm(); // Constructor
    RobotomyRequestForm(std::string target); //Name constructor
    RobotomyRequestForm(const RobotomyRequestForm& copy);//Copy constructor
    RobotomyRequestForm& operator= (const RobotomyRequestForm& copy); //Copy assignment op
    //Getters:
    std::string getTarget() const;
    //Setters:
    void        setTarget(std::string);
    //My methods:
    void        executeAction(const Bureaucrat& executer) const;
    ~RobotomyRequestForm(); // Destructor

private:
    std::string   _target;
};

std::ostream&       operator<<(std::ostream& out, RobotomyRequestForm& src);

#endif // FORM_H