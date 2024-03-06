#include "includes/Zombie.hpp"

int main()
{   
    char *input = new char[4096];
    std::string name;

    std::cout << "You're about to create a horde of zombies...\n";
    sleep(3);
    std::system("clear");
    std::cout << RED << "\033[5m\n\n\t\tBE CAREFULL!!!\n" << RESET;
    sleep(5);
    std::system("clear");
    std::cout << "\n\tHow many Zombies should form the Zombie Horde?\n\n";
    sleep(2);
    std::cout << "It's up to you: ";
    std::cin >> input;
    if(std::cin.eof())
        exit(0);
    std::cout << "Give them a name: ";
    std::cin >> name;
    if(std::cin.eof())
        exit(0);
    std::system("clear");
    int NZ = std::atoi((const char *)input);
    delete[] input;
    Zombie *zb = zombieHorde(NZ, name);
    for(int i = 0; i < NZ; i++){
        zb[i].announce();
    }
    delete[] zb;
}