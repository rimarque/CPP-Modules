#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl    harl;

    if(argc < 2 || argc > 2){
        std::cout << "That's the worng number of arguments you fool!!\n";
        return 1;
    }
    harl.complain(argv[1]);
}