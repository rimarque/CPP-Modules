#include "includes/PmergeMe.hpp"

MyException::MyException(): _msg("Error") {}

MyException::MyException(const std::string& msg): _msg(msg) {}

const char* MyException::what() const throw(){
    return _msg.c_str();
}

MyException::~MyException() throw() {}

PmergeMe::PmergeMe() {
    std::cout << BOLD_WHITE << "PmergeMe" << RESET 
    << " default constructor called" << std::endl;
}

PmergeMe::PmergeMe(std::vector<int> vec) {
    _vec = vec;
    std::deque<int> deq(vec.begin(), vec.end());
    _deq = deq;
    std::cout << BOLD_WHITE << "PmergeMe" << RESET 
    << " default constructor called" << std::endl;
}

// Copy constructor
PmergeMe::PmergeMe(const PmergeMe& copy) {
    _vec = copy._vec;
    _deq = copy._deq;
    _vecpairs = copy._vecpairs;
    _deqpairs = copy._deqpairs;
    std::cout << BOLD_WHITE << "PmergeMe" << RESET 
    << " copy constructor called" << std::endl;
}

// Copy assignment operator overload
PmergeMe& PmergeMe::operator= (const PmergeMe& copy) {
    // Self-assignment check
    if (this == &copy)
        return *this;
    _vec = copy._vec;
    _deq = copy._deq;
    _vecpairs = copy._vecpairs;
    _deqpairs = copy._deqpairs;
    std::cout << BOLD_WHITE << "PmergeMe" << RESET 
    << " copy assignment operator overload" << std::endl;
    return *this;
}

void  PmergeMe::makePairs(){
    std::cout << "make pairs\n";
    for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); ++it){
        if(it + 1 == _vec.end())
            _vecpairs.push_back(std::make_pair(0, *it)); //zero means empty
        else{
            _vecpairs.push_back(std::make_pair(*it, *(it + 1)));
            ++it;
        }
    }
}

void  PmergeMe::sortPairs(){
    std::cout << "sort pairs\n";
    for (std::vector<std::pair<int, int> >::iterator it = _vecpairs.begin(); it != _vecpairs.end() && it->first != 0; ++it){
        if(it->second > it->first) //zero means empty
            std::swap(it->first, it->second);
    }
}


//partition puts all numbers smaller then or equal to pivot to its left and bigger to its right
//returns the index where pivot was placed
int partition(std::vector<std::pair<int, int> >& vec, int low, int high) {
    int pivot = vec[high].first; // Escolhe o último elemento como pivô
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (vec[j].first <= pivot) {
            ++i;
            std::swap(vec[i], vec[j]);
        }
    }
    std::swap(vec[i + 1], vec[high]);
    return i + 1;
}

//quicksort_vecpair will sort the vecpair by the first of each pair (highest value of the pair)
//It's a Divide and Conquer algorithm that picks the last element as a pivot and partitions 
//the given vector around it by placing the pivot in its correct position in the sorted vec. 
void quicksort_vecpair(std::vector<std::pair<int, int> >& vec, int low, int high) {
    if (low < high) {
        int index_pivot = partition(vec, low, high);

        quicksort_vecpair(vec, low, index_pivot - 1);
        quicksort_vecpair(vec, index_pivot + 1, high);
    }
}

void PmergeMe::insertion(){
    std::vector<int> sorted;
    for (std::vector<std::pair<int, int> >::iterator it = _vecpairs.begin(); it != _vecpairs.end() && it->first != 0; ++it){
        sorted.push_back(it->first);
    }
    std::vector<int> pend;
    for (std::vector<std::pair<int, int> >::iterator it = _vecpairs.begin(); it != _vecpairs.end(); ++it){
        pend.push_back(it->second);
    }
    std::cout << "sorted\n";
    printContainer(sorted);
    std::cout << "pend\n";
    printContainer(pend);
    std::vector<std::pair<int, int> > pend_sorted_indexes = getInsertInfo(_pend.size());
    
}

std::vector<int> PmergeMe::fordJohnsonVec(){
    this->makePairs();
    printPairs(_vecpairs);
    this->sortPairs();
    printPairs(_vecpairs);
    std::cout << "quicksort vecpairs\n";
    if(_vecpairs[_vecpairs.size() - 1].first == 0)
        quicksort_vecpair(_vecpairs, 0, _vecpairs.size() - 2);
    else
        quicksort_vecpair(_vecpairs, 0, _vecpairs.size() - 1);
    printPairs(_vecpairs);
    this->insertion();
    return _sortedvec;
}

//std::vector<int> PmergeMe::fordJonhsonDeq(){}

PmergeMe::~PmergeMe() {
    std::cout << BOLD_WHITE << "PmergeMe" << RESET 
    << " destructor called" << std::endl;
}
