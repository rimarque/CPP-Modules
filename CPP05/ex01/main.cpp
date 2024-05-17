#include "includes/Form.hpp"

void    set_input(std::string *bName, std::string *fName, int *bGrade, int *fGradeSign, int *fGradeExec){
    std::string input;

    std::cout << "What should be the name of our Bureaucrat?" << std::endl;
    std::getline(std::cin, *bName);
    if(std::cin.eof())
		exit(0);
    std::cout << "What should be their grade?" << std::endl << "Valid grades range from 150 (lowest) to 1 (highest),"
    << " feel free to test with invalid grades!" << std::endl;
    std::cin >> input;
    if(std::cin.eof())
		exit(0);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    *bGrade = std::atoi(input.c_str());
    std::cout << "Lets create a form! What should be it's name?" << std::endl;
    std::getline(std::cin, *fName);
    if(std::cin.eof())
		exit(0);
    std::cout << "What should be the grade required to sign the form?" << std::endl << "Valid grades range from 150 (lowest) to 1 (highest),"
    << " feel free to test with invalid grades!" << std::endl;
    std::cin >> input;
    if(std::cin.eof())
		exit(0);
    *fGradeSign = std::atoi(input.c_str());
    std::cout << "What should be the grade required to execute the form?" << std::endl << "Valid grades range from 150 (lowest) to 1 (highest),"
    << " feel free to test with invalid grades!" << std::endl;
    std::cin >> input;
    if(std::cin.eof())
		exit(0);
    *fGradeExec = std::atoi(input.c_str());
    std::cout << GREEN << "Thanks for the info! Are you ready for testing?" << std::endl 
    << "(press y for yes, anyting else will make you exit the program)" << RESET << std::endl;
    std::cin >> input;
    if(std::cin.eof())
		exit(0);
    std::system("clear");
}

void    test_const_copy(Form& form)
{
    std::cout << GREEN << std::endl << "-------Creating a copy of the form, using copy constructor" << RESET << std::endl;
    Form    copy1(form);
    std::cout << GREEN << std::endl << "-------Creating a form, using default constructor" << RESET << std::endl;
    Form    copy2;
    std::cout << std::endl << CYAN << "-------Testing atributes constructor" << RESET << std::endl;
    std::cout << form << std::endl;
    std::cout << std::endl << CYAN << "-------Testing copy constructor" << RESET << std::endl;
    std::cout << copy1 << std::endl;
    std::cout << std::endl << CYAN << "-------Testing default constructor" << RESET << std::endl;
    std::cout << copy2 << std::endl;
    std::cout << std::endl << CYAN << "-------Testing copy assigment operator (copying copy to default)" << RESET << std::endl;
    copy2 = copy1;
    std::cout << copy2 << std::endl;
}
void    test_beSigned(Form& form, Form form2, Bureaucrat bure, Bureaucrat newBure)
{
    std::cout << std::endl << CYAN << "-------Testing beSigned: " << RESET << std::endl;
    std::cout << std::endl << CYAN << "-------Form1, Bureaucrat1: " << RESET;
    form.beSigned(bure);
    std::cout << std::endl << CYAN << "-------Form1, Bureaucrat1: " << RESET;
    form.beSigned(bure);
    std::cout << std::endl << CYAN << "-------Form2, Bureaucrat2: " << RESET;
    form2.beSigned(newBure);
    std::cout << std::endl;
}

void    test_signForm(Form& form, Form form2, Bureaucrat bure, Bureaucrat newBure)
{
    std::cout << std::endl << CYAN << "-------Testing beSigned: " << RESET << std::endl;
    std::cout << std::endl << CYAN << "-------Form1, Bureaucrat1: " << RESET;
    bure.signForm(form);
    std::cout << std::endl << CYAN << "-------Form1, Bureaucrat1: " << RESET;
    bure.signForm(form);
    std::cout << std::endl << CYAN << "-------Form2, Bureaucrat2: " << RESET;
    form2.beSigned(newBure);
    std::cout << std::endl;

}

void    test_form(Bureaucrat& bure, Form& form, int test) {
    std::string formName2("form2");
    std::string formName3("form3");

    std::cout << GREEN << std::endl << "-------Creating bureaucrat2" << RESET << std::endl;
    Bureaucrat    newBure;
    std::cout << GREEN << std::endl << "-------Creating form2" << RESET << std::endl;
    Form    form2(formName2);
    std::cout << GREEN << std::endl << "-------Creating form 3" << RESET << std::endl;
    Form    form3(formName3);
    std::cout << std::endl;

    std::cout << CYAN << std::endl << "-------Display bureaucrat2" << RESET << std::endl;
    std::cout << newBure << std::endl;
    std::cout << CYAN << std::endl << "-------Display form2" << RESET << std::endl;
    std::cout << form2 << std::endl;
    std::cout << CYAN << std::endl << "-------Display form3" << RESET << std::endl;
    std::cout << form3 << std::endl;
    std::cout << std::endl;
    
    if(test == 1)
        test_beSigned();
    if(test == 2)
        test_signForm();
    std::cout << std::endl << CYAN << "-------Testing signForm: " << RESET << std::endl;
    std::cout << std::endl << CYAN << "-------Form1, Bureaucrat1" << RESET;
    bure.signForm(form);
    std::cout << std::endl << CYAN << "-------Form2, Bureaucrat1" << RESET;
    bure.signForm(form2);
    std::cout << std::endl << CYAN << "-------Form3, Bureaucrat2: " << RESET;
    newBure.signForm(form3);
    std::cout << std::endl;
}

int main()
{
    std::string bName;
    std::string fName;
    int         bGrade;
    int         fGradeSign;
    int         fGradeExec;

    set_input(&bName, &fName, &bGrade, &fGradeSign, &fGradeExec);
    try{
        std::cout << GREEN << std::endl << "-------Creating a Bureaucrat, using atributes constructor" << RESET << std::endl;
        Bureaucrat bure(bName, bGrade);
        std::cout << GREEN << std::endl << "-------Creating a Form, using atributes constructor" << RESET << std::endl;
        Form       form(fName, fGradeSign, fGradeExec);
        test_const_copy(form);
        test_form(bure, form);
    }
    catch (const std::exception& e) {
            std::cerr << std::endl << e.what() << std::endl << std::endl;
    }
}