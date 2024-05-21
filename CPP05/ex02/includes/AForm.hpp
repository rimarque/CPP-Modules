#ifndef AFORM_H
# define AFORM_H

# include "Bureaucrat.hpp"

class AForm {
public:
    class GradeTooHighException: public std::exception {
        public:
            virtual const char* what() const throw();
    };
    class GradeTooLowException: public std::exception {
        public:
            virtual const char* what() const throw();
    };
    class FormIsSignedException: public std::exception {
        public:
            virtual const char* what() const throw();
    };
    AForm(); // Constructor
    AForm(std::string& name); //Name constructor
    AForm(std::string& name, int gradeToSign, int gradeToExecute); //Atributes constructor
    AForm(const AForm& copy);//Copy constructor
    virtual AForm& operator= (const AForm& copy); //Copy assignment constructor
    //Getters:
    virtual const std::string&  getName() const;
    virtual const int           getGradeToSign() const;
    virtual const int           getGradeToExecute() const;
    virtual bool                isSigned() const;
    virtual void                beSigned(const Bureaucrat& bureaucrat);
    virtual void                execute(Bureaucrat const& executor) = 0;
    ~AForm(); // Destructor

private:
    const std::string   _name;
    bool                _signed;
    const int           _gradeToSign;
    const int           _gradeToExecute;
};

#endif // FORM_H
