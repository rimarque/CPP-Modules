#include "includes/BitcoinExchange.hpp"

int main(int argc, char **argv){
    try{
        //Validar o numero de argumentos
        if(argc != 2)
            throw MyException("Error: the program takes one argument (whatever.txt file)");
        std::string file = argv[1];
        BitcoinExchange excangeRate;
    }
    catch(const std::exception& e){
        std::cerr << e.what() << std::endl;
    }
}