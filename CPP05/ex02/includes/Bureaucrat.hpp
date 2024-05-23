#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <fstream>
# include <string.h>
# include <unistd.h>
# include <cstdlib>
# include <ctime>
# include <stdexcept>
#include  <limits>
# define RED "\033[31m"
# define GREEN "\033[32m"
# define PURPLE "\033[35m"
# define YELLOW "\033[33m"
# define WHITE "\033[37m"
# define CYAN "\033[36m"
# define BOLD_RED "\033[1;31m"
# define BOLD_GREEN "\033[1;32m"
# define BOLD_PURPLE "\033[1;35m"
# define BOLD_YELLOW "\033[1;33m"
# define BOLD_WHITE 	"\033[1;37m"
# define BOLD_CYAN "\033[1;36m"
# define RESET "\033[0m"

class AForm;

class Bureaucrat {
public:
    class GradeTooHighException: public std::exception {
        public:
            virtual const char* what() const throw();
    };
    class GradeTooLowException: public std::exception {
        public:
            virtual const char* what() const throw();
    };
    Bureaucrat(); // Constructor
    Bureaucrat(std::string name, int grade); //atributes constructor
    Bureaucrat(const Bureaucrat& copy);//Copy constructor
    Bureaucrat&         operator= (const Bureaucrat& copy); //Copy assignment constructor
    //Getters:
    const std::string&  getName() const;
    int                 getGrade() const;
    //Increment/decrement grade
    void                incrementGrade();
    void                decrementGrade();
    //signForm
    void                signForm(AForm& form) const;
    //executeForm
    void                executeForm(AForm const & form);
    ~Bureaucrat(); // Destructor

private:
    const std::string   _name;
    int                 _grade;
};

std::ostream&       operator<<(std::ostream& out, Bureaucrat& src);

#endif // BUREAUCRAT_H
