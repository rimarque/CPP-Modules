#ifndef AFORM_HPP
# define AFORM_HPP

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
    class FormNotSignedException: public std::exception {
        public:
            virtual const char* what() const throw();
    };
    AForm(); // Constructor
    AForm(std::string& name); //Name constructor
    AForm(std::string name, int gradeToSign, int gradeToExecute); //Atributes constructor
    AForm(const AForm& copy);//Copy constructor
    AForm& operator= (const AForm& copy); //Copy assignment constructor
    //Getters:
    const std::string&  getName() const;
    int           getGradeToSign() const;
    int           getGradeToExecute() const;
    bool                isSigned() const;
    //Setters:
    void                setSigned(bool);
    //My functions
    void                beSigned(const Bureaucrat& bureaucrat);
    void                execute(Bureaucrat const& executor) const;
    virtual void        executeAction() const = 0;
    virtual ~AForm(); // Destructor

private:
    const std::string   _name;
    bool                _signed;
    const int           _gradeToSign;
    const int           _gradeToExecute;
};

std::ostream&       operator<<(std::ostream& out, AForm& src);

#endif // FORM_H
