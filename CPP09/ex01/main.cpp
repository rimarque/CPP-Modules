#include "includes/RPN.hpp"
 

std::queue<int> str_to_queue(const std::string& str){
    std::stringstream str_stream(str);
    std::string word;
    std::queue<int> q;

    while (str_stream >> word) {
        if(word.length() > 1)
            throw MyException("Error: mathematical expression may include digits (from 0 to 9) and operators (+ - / *) only");
        char c = *word.begin();
        if(std::isdigit(c))
            q.push(atoi(word.c_str()));
        else if(c == '-' || c == '+' || c == '/' || c == '*')
            q.push(c);
        else
            throw MyException("Error: mathematical expression may include digits (from 0 to 9) and operators (+ - / *) only");
    }
    return q;
}

int main(int argc, char **argv){
    try{
        if(argc != 2)
            throw MyException("Usage: ./RPN \"mathematical expression\"");
        std::queue<int> q = str_to_queue(argv[1]);
        RPN calculator;
        std::cout << calculator.calculate(q) << std::endl;
    }
    catch(std::exception& e){
        std::cerr << e.what() << std::endl;
    }

}