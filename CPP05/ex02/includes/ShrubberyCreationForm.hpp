#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM__HPP

# include "AForm.hpp"

class ShrubberyCreationForm: public AForm 
{
    public:
        class FileUnableToOpenException: public std::exception {
            public:
                virtual const char* what() const throw();
        };
        ShrubberyCreationForm(); // Constructor
        ShrubberyCreationForm(std::string target); //Name constructor
        ShrubberyCreationForm(const ShrubberyCreationForm& copy);//Copy constructor
        ShrubberyCreationForm& operator= (const ShrubberyCreationForm& copy); //Copy assignment op
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

std::ostream&       operator<<(std::ostream& out, ShrubberyCreationForm& src);

#endif // FORM_H