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
            _vecpairs.push_back(std::make_pair(0, *it)); //zero means nothing
        else{
            _vecpairs.push_back(std::make_pair(*it, *(it + 1)));
            ++it;
        }
    }
    std::cout << "make pairs end\n";
}

void  PmergeMe::sortPairs(){
    std::cout << "sort pairs\n";
    for (std::vector<std::pair<int, int> >::iterator it = _vecpairs.begin(); it != _vecpairs.end(); ++it){
        if(it->first != 0 && it->second > it->first)
            std::swap(it->first, it->second);//zero means nothing
    }
}

std::vector<int> PmergeMe::fordJohnsonVec(){
    std::vector<int> sortedVec;

    this->makePairs();
    this->sortPairs();
    //this->quicksort_vecpairs();
    printPairs(_vecpairs);
    return sortedVec;
}

//std::vector<int> PmergeMe::fordJonhsonDeq(){}

PmergeMe::~PmergeMe() {
    std::cout << BOLD_WHITE << "PmergeMe" << RESET 
    << " destructor called" << std::endl;
}
