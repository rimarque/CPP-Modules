#include "includes/BitcoinExchange.hpp"


int main(int argc, char **argv){
    try{
        //Validar o numero de argumentos
        if(argc != 2)
            throw MyException("Error: the program takes one argument");
        
        //Abrir o ficheiro
        std::string file = argv[1];
        BitcoinExchange exchangeRate;
        std::ifstream input_file(file.c_str());
        if (!input_file.is_open())
            throw MyException("Error opening file: " + file);


        //Ver se o ficheiro está vazio e validar o header
        std::string line;
        std::getline(input_file, line);
        if(input_file.eof()){
            input_file.close();
            throw MyException("Error: empty file => " + file);
        }
        if(line != "date | value"){
            input_file.close();
            throw MyException("Error: invalid header => " + file);
        }

        //Ler o ficheiro e imprimir o output
        while (std::getline(input_file, line)) {
            std::istringstream input_line(line);
            std::string key, value;
            std::getline(input_line, key, '|');
            //Linha sem delimitador
            if(input_line.eof() == true){
                std::cerr << "Error: bad input => " + key << std::endl;
                continue;
            }
            std::getline(input_line, value);
            //Nada após delimitador
            if(value.empty()){
                std::cerr << "Error: bad input => " + line << std::endl;
                continue;
            }
            //Validar data
            if(!valid_date(key, '|')){
                std::cerr << "Error: bad input => " + line << std::endl;
                continue;
            }
            try{
                //Validar valor
                float number = getvalue(value, line, '|');
                std::cout << key << "=> " << number << " = " 
                << exchangeRate.convert(key.substr(0, key.length() - 1), number) << std::endl;
            }
            catch(std::exception& e){
                std::cerr << e.what() << std::endl;
            }
        }
        input_file.close();
    }
    catch(const std::exception& e){
        std::cerr << e.what() << std::endl;
    }
}