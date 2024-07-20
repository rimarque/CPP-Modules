#include "includes/PmergeMe.hpp"

//Vector vs Deque
/* Contiguous Memory: std::vector stores elements contiguously, which can be more cache-friendly and efficient for random access. std::deque uses a segmented approach.
Insertion/Deletion Efficiency: std::deque allows efficient insertion and deletion at both ends, while std::vector is more efficient for operations at the end.
Random Access: Both std::vector and std::deque provide constant time random access, but std::vector benefits from contiguous memory layout.
Memory Management: std::vector may involve reallocations and copying when resizing, while std::deque manages its capacity through segment management without the need for reallocation. 
Deque provides a balanced approach between insertion efficiency and random access.*/

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

template <typename T>
bool isOrdered(T container){
    for(int i = static_cast<int>(container.size() - 1); i > 0; --i){
        if(container[i] < container[i - 1])
            return false;
    }
    return true;
}

std::vector<int> verify_input(char **argv){
    std::vector <int> vec;

    for(int i = 1; argv[i]; ++i) {
        if(isPosInt(argv[i]) == false){
            throw MyException("Error: only positive intergers can be used as argument");
        }
        vec.push_back(atoi(argv[i]));
    }
    if (isOrdered(vec))
        throw MyException("Sequence is already sorted, try again");
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
        PmergeMe<std::vector<int> > sortvec(vec);
        gettimeofday(&start, NULL);
        std::vector<int> sorted_vec = sortvec.fordJohnsonAlgorithm(false);
        gettimeofday(&end, NULL);
        double sorting_time_vec = getTimeInMicroSec(start, end);
        if (isOrdered(sorted_vec) == false)
            throw MyException("Error: sequence not sorted");
        PmergeMe<std::deque<int> > sortdeq(deq);
        gettimeofday(&start, NULL);
        std::deque<int> sorted_deq = sortdeq.fordJohnsonAlgorithm(false);
        gettimeofday(&end, NULL);
        double sorting_time_deq = getTimeInMicroSec(start, end);
        if (isOrdered(sorted_deq) == false)
            throw MyException("Error: sequence not sorted");
        std::cout << "Before: ";
        printContainer(vec);
        std::cout << "After: ";
        printContainer(sorted_vec);
        std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " 
        <<  sorting_time_vec + data_managment_time << " us\n";
        std::cout << "Time to process a range of " << vec.size() << " elements with std::deque: " 
        << sorting_time_deq + data_managment_time << " us\n";
    }
    catch(std::exception& e){
        std::cout << e.what() << std::endl;
    }
}