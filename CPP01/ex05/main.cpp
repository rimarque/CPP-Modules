#include "Harl.hpp"

int main()
{
    Harl    harl;
    std::string buff;

    std::cout << "Let's help Harl complain!\nTell me, what should Harl complain about?\n";
    std::cout << BLINK << GREEN << "debug\t" << YELLOW << "info\t" << PURPLE << "warning    " << RED << "error\n" << RESET;
    std::cin >> buff;
    if(std::cin.eof())
        exit(0);
    std::system("clear");
    std::cout << "\n\n\n\n";
    harl.complain(buff);
    std::cout << "\n\n\n\n";
}