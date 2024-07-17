#include "includes/PmergeMe.hpp"

MyException::MyException(): _msg("Error") {}

MyException::MyException(const std::string& msg): _msg(msg) {}

const char* MyException::what() const throw(){
    return _msg.c_str();
}

MyException::~MyException() throw() {}

template <typename T>
PmergeMe<T>::PmergeMe() {
    std::cout << BOLD_WHITE << "PmergeMe" << RESET 
    << " default constructor called" << std::endl;
}

template <typename T>
PmergeMe<T>::PmergeMe(const T& input) {
    _input = input;
    std::cout << BOLD_WHITE << "PmergeMe" << RESET 
    << " default constructor called" << std::endl;
}

// Copy constructor
template <typename T>
PmergeMe<T>::PmergeMe(const PmergeMe& copy) {
    _input = copy._input;
    std::cout << BOLD_WHITE << "PmergeMe" << RESET 
    << " copy constructor called" << std::endl;
}

// Copy assignment operator overload
template <typename T>
PmergeMe<T>& PmergeMe<T>::operator= (const PmergeMe<T>& copy) {
    // Self-assignment check
    if (this == &copy)
        return *this;
    _input = copy._input;
    std::cout << BOLD_WHITE << "PmergeMe" << RESET 
    << " copy assignment operator overload" << std::endl;
    return *this;
}

template <typename T>
void  PmergeMe<T>::makePairs(){
    std::cout << "make pairs\n";
    for (std::vector<int>::iterator it = _input.begin(); it != _input.end(); ++it){
        if(it + 1 == _input.end())
            _pairs.push_back(std::make_pair(0, *it)); //zero means empty
        else{
            _pairs.push_back(std::make_pair(*it, *(it + 1)));
            ++it;
        }
    }
}

template <typename T>
void  PmergeMe<T>::sortPairs(){
    std::cout << "sort pairs\n";
    for (std::vector<std::pair<int, int> >::iterator it = _pairs.begin(); it != _pairs.end() && it->first != 0; ++it){
        if(it->second > it->first) //zero means empty
            std::swap(it->first, it->second);
    }
}


//partition puts all numbers smaller then or equal to pivot to its left and bigger to its right
//returns the index where pivot was placed
int partition(other& vec, int low, int high) {
    int pivot = vec[high].first; // Escolhe o último elemento como pivô
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (vec[j].first <= pivot) {
            ++i;
            std::swap(vec[i], vec[j]); // movendo elementos menores que o pivô para a esquerda
        }
    }
    //Após completar o loop, troca o pivô com o elemento imediatamente após o último elemento menor que o pivô
    std::swap(vec[i + 1], vec[high]);
    return i + 1;
}

//quicksort_pair will sort the vecpair by the first of each pair (highest value of the pair)
//It's a Divide and Conquer algorithm that picks the last element as a pivot and partitions 
//the given vector around it by placing the pivot in its correct position in the sorted vec. 
void quicksort_pair(std::vector<std::pair<int, int> >& vec, int low, int high) {
    if (low < high) {
        int index_pivot = partition(vec, low, high);

        quicksort_pair(vec, low, index_pivot - 1);
        quicksort_pair(vec, index_pivot + 1, high);
    }
}

//returns the next number in the jacobstal sequence, starting at 3
int getJacobstalNumber(){
    static int before_number = 1;
    static int number = 1;
    int result = number + 2 * before_number;
    before_number = number;
    number = result;
    return result;
}

/*Yes, you can use the std::lower_bound function from the C++ Standard Library. 
This function returns an iterator pointing to the first element in the range that is not less than the specified value. 
If all elements in the range are less than the specified value, it returns an iterator pointing to the end of the range.*/
//Usa std::lower_bound para encontrar a posição de inserção
//std::vector<int>::iterator it = std::lower_bound(vec.begin(), vec.end(), target);
//Insere o target na posição correta
//vec.insert(it, target);

//starting index to insert = sequencia de jacobstal - 1; 
//insertion area size = 2^x -1 (x comeca no 2, sequencia de jacobstal comeca no 3, ou seja starting index to insert comeca no 2)
template <typename T>
void PmergeMe<T>::insertion(){
    for (std::vector<std::pair<int, int> >::iterator it = _pairs.begin(); it != _pairs.end() && it->first != 0; ++it){
        _sorted.push_back(it->first);
    }
    for (std::vector<std::pair<int, int> >::iterator it = _pairs.begin(); it != _pairs.end(); ++it){
        _pend.push_back(it->second);
    }
    std::cout << "_sorted\n";
    printContainer(_sorted);
    std::cout << "_pend\n";
    printContainer(_pend);
    _sorted.insert(_sorted.begin(), _pend[0]);
    int last_starting_index = 0;
    int x = 2;
    while(last_starting_index < static_cast<int>(_pend.size()) - 1){
        int insertion_area_size = std::min(static_cast<int>(std::pow(2, x++)) - 1, static_cast<int>(_sorted.size()));
        int starting_index = std::min(getJacobstalNumber() - 1, static_cast<int>(_pend.size()) - 1);
        for(int j = starting_index; j > last_starting_index; --j){
            std::vector<int>::iterator it = std::lower_bound(_sorted.begin(), _sorted.begin() + insertion_area_size, _pend[j]);
            _sorted.insert(it, _pend[j]);
        }
        last_starting_index = starting_index;
    }
}

template <typename T>
std::T<int> PmergeMe<T>::fordJohnson(){
    this->makePairs();
    printPairs(_pairs);
    this->sortPairs();
    printPairs(_pairs);
    std::cout << "quicksort vecpairs\n";
    if(_pairs[_pairs.size() - 1].first == 0)
        quicksort_pair(_pairs, 0, _pairs.size() - 2);
    else
        quicksort_pair(_pairs, 0, _pairs.size() - 1);
    printPairs(_pairs);
    this->insertion();
    return _sorted;
}

//std::vector<int> PmergeMe::fordJonhsonDeq(){}
PmergeMe<T>::~PmergeMe() {
    std::cout << BOLD_WHITE << "PmergeMe" << RESET 
    << " destructor called" << std::endl;
}
