#include "includes/PmergeMe.hpp"

#include "includes/PmergeMe.hpp"
#include <sys/time.h>
#include <bits/stdc++.h>

//positive intergers
//verify_input()
/* Before: 3 5 9 7 4
After: 3 4 5 7 9
Time to process a range of 5 elements with std::[..] : 0.00031 us
Time to process a range of 5 elements with std::[..] : 0.00014 us */

//FUNÇÃO DO TEMPO ESTÁ MAL
double getTimeInMicroSec(timeval start, timeval end){
        double seconds = end.tv_sec - start.tv_sec;
        double microseconds = end.tv_usec - start.tv_usec;
        return ((seconds * 1000000.0) + microseconds);
}

//Ja ta organizada
//Ver se ta organizada e se tem a mesma quantidade de numeros
bool    hasNonNumericChar(std::string str)
{
  for (std::string::const_iterator i = str.begin(); i != str.end(); ++i) {
        if (!std::isdigit(*i))
            return true;
  }
  return false;
}

bool isPosInt(std::string str){
    if(str.empty() || (hasNonNumericChar(str) == true))
        return false;
    long number = atol(str.c_str());
    if(number < 1 || number > INT_MAX)
        return false;
    return true;
}

std::vector<int> verify_input(char **argv){
    std::vector <int> vec;

    for(int i = 1; argv[i]; ++i) {
        std::cout << argv[i] << std::endl;
        if(isPosInt(argv[i]) == false){
            std::cout << argv[i] << std::endl;
            throw MyException("Error: only positive intergers can be used as argument");
        }
        vec.push_back(atoi(argv[i]));
    }
    return vec;
}

int main(int argc, char **argv){
    timeval start, end;
    try{
        if(argc < 3){
            throw MyException("Error: not enough arguments");
        }
        gettimeofday(&start, NULL);
        std::vector<int> vec = verify_input(argv);
        std::deque<int> deq(vec.begin(), vec.end());
        gettimeofday(&end, NULL);
        double data_managment_time = getTimeInMicroSec(start, end);
        std::cout << "Data managment time " << std::fixed << std::setprecision(2) 
        << data_managment_time << " us\n";
        std::cout << "Before vec: ";
        printContainer(vec);
        std::cout << "Before deq: ";
        printContainer(deq);
        PmergeMe sortvec(vec);
        gettimeofday(&start, NULL);
        std::vector<int> sorted_vec = sortvec.fordJohnson();
        gettimeofday(&end, NULL);
        double sorting_time_vec = getTimeInMicroSec(start, end);
        /*PmergeMe sortdeq(deq);
        gettimeofday(&start, NULL);
        std::vector<int> sorted_deq = sortdeq.fordJohnson();
        gettimeofday(&end, NULL);
        double sorting_time_deq = getTimeInMicroSec(start, end); */
        std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nAfter vec: ";
        printContainer(sorted_vec);
/*         std::cout << "After deq: ";
        printContainer(sorted_deq) */;
        std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " 
        <<  sorting_time_vec + data_managment_time << " us\n";
        /*std::cout << "Time to process a range of " << vec.size() << " elements with std::deque: " 
        << sorting_time_deq + data_managment_time << " us\n"; */
    }
    catch(std::exception& e){
        std::cout << e.what() << std::endl;
    }
}