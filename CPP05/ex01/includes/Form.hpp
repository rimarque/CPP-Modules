#ifndef FORM_H
# define FORM_H

# include "Bureaucrat.hpp"

class Form {
public:
    class GradeTooHighException: public std::exception {
        public:
            virtual const char* what() const throw();
    };
    class GradeTooLowException: public std::exception {
        public:
            virtual const char* what() const throw();
    };
    Form(); // Constructor
    Form(std::string& name); //Name constructor
    Form(std::string& name, int gradeToSign, int gradeToExecute); //Atributes constructor
    Form(const Form& copy);//Copy constructor
    Form& operator= (const Form& copy); //Copy assignment constructor
    //Getters:
    const std::string&  getName() const;
    int                 getGradeToSign() const;
    int                 getGradeToExecute() const;
    bool                isSigned() const;
    void                beSigned(Bureaucrat& bureaucrat);
    ~Form(); // Destructor

private:
    const std::string   _name;
    bool                _signed;
    const int           _gradeToSign;
    const int           _gradeToExecute;
};

std::ostream&       operator<<(std::ostream& out, Form& src);

#endif // FORM_H
