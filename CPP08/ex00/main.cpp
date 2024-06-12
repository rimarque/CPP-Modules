#include "easyfind.hpp"

int main(){
    int n;
    srand(time(NULL));
    std::cout << CYAN << "------Testing vector\n" << RESET;
    std::vector<int> vec;
    n = rand();
    for(int i = 0; i < 5; i++){
        if(i == 1 || i == 4)
            vec.push_back(n);
        else
            vec.push_back(rand());
    }
    printContainer(vec);
    try{
        std::vector<int>::iterator it = easyfind(vec, 1);
        std::cout << "Found value at position: " << std::distance(vec.begin(), it) << std::endl;
    }
    catch(std::exception& e){
        std::cerr << e.what() << std::endl;
    }
    try{
        std::vector<int>::iterator it = easyfind(vec, n);
        std::cout << "Found value at position: " << std::distance(vec.begin(), it) << std::endl;
    }
    catch(std::exception& e){
        std::cerr << e.what() << std::endl;
    }
    std::cout << CYAN << "------Testing deque\n" << RESET;
    std::deque<int> deq;
    n = rand();
    for(int i = 0; i < 5; i++){
        if(i == 2 || i == 4)
            deq.push_back(n);
        else
            deq.push_back(rand());
    }
    printContainer(deq);
    try{
        std::deque<int>::iterator it = easyfind(deq, 1);
        std::cout << "Found value at position: " << std::distance(deq.begin(), it) << std::endl;
    }
    catch(std::exception& e){
        std::cerr << e.what() << std::endl;
    }
    try{
        std::deque<int>::iterator it = easyfind(deq, n);
        std::cout << "Found value at position: " << std::distance(deq.begin(), it) << std::endl;
    }
    catch(std::exception& e){
        std::cerr << e.what() << std::endl;
    }
    std::cout << CYAN << "------Testing list\n" << RESET;
    std::list<int> lis;
    n = rand();
    for(int i = 0; i < 5; i++){
        if(i == 3 || i == 4)
            lis.push_back(n);
        else
            lis.push_back(rand());
    }
    printContainer(lis);
    try{
        std::list<int>::iterator it = easyfind(lis, 1);
        std::cout << "Found value at position: " << std::distance(lis.begin(), it) << std::endl;
    }
    catch(std::exception& e){
        std::cerr << e.what() << std::endl;
    }
    try{
        std::list<int>::iterator it = easyfind(lis, n);
        std::cout << "Found value at position: " << std::distance(lis.begin(), it) << std::endl;
    }
    catch(std::exception& e){
        std::cerr << e.what() << std::endl;
    }
    std::cout << CYAN << "------Testing non int vector\n" << RESET;
    std::vector<char> vecC;
    n = rand();
    for(int i = 0; i < 5; i++){
        if(i == 0 || i == 4)
            vecC.push_back(n);
        else
            vecC.push_back(rand());
    }
    printContainer(vecC);
    try{
        std::vector<char>::iterator it = easyfind(vecC, 1);
        std::cout << "Found value at position: " << std::distance(vecC.begin(), it) << std::endl;
    }
    catch(std::exception& e){
        std::cerr << e.what() << std::endl;
    }
    try{
        std::vector<char>::iterator it = easyfind(vecC, n);
        std::cout << "Found value at position: " << std::distance(vecC.begin(), it) << std::endl;
    }
    catch(std::exception& e){
        std::cerr << e.what() << std::endl;
    }
}