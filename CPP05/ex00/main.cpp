#include "includes/Bureaucrat.hpp"

int main()
{
    try{
        Bureaucrat a("adolfo", 7);
        a.incrementGrade();
        a.decrementGrade();
        std::cout << a << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}