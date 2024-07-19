#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string.h>
# include <unistd.h>
# include <cstdlib>
# include <ctime>
# include <vector>
# include <deque>
# include <iterator>
# include <utility>  // Para std::pair e std::make_pair
# include <cmath>   //para o power of
# include <algorithm> //para o std::min
# include <sys/time.h>
# include <bits/stdc++.h>
# define RED "\033[31m"
# define GREEN "\033[32m"
# define PURPLE "\033[35m"
# define YELLOW "\033[33m"
# define WHITE "\033[37m"
# define CYAN "\033[36m"
# define BOLD_RED "\033[1;31m"
# define BOLD_GREEN "\033[1;32m"
# define BOLD_PURPLE "\033[1;35m"
# define BOLD_YELLOW "\033[1;33m"
# define BOLD_WHITE 	"\033[1;37m"
# define BOLD_CYAN "\033[1;36m"
# define RESET "\033[0m"
# include <stdexcept>

class MyException: public std::exception {
    public:
        MyException();
        MyException(const std::string& msg);
        virtual const char* what() const throw();
        virtual ~MyException() throw();
    private:
        std::string _msg;
};

// Type trait to define Pairs based on Container
template <typename Container>
struct PairsType;

// Specialization for std::vector<int>
template <>
struct PairsType<std::vector<int> > {
    typedef std::vector<std::pair<int, int> > Type;
};

// Specialization for std::deque<int>
template <>
struct PairsType<std::deque<int> > {
    typedef std::deque<std::pair<int, int> > Type;
};

//Transformar class em template
template <typename Container>
class PmergeMe {
public:
    typedef typename PairsType<Container>::Type Pairs;
    PmergeMe(); // Constructor
    PmergeMe(const Container& input);
    PmergeMe(const PmergeMe& copy);//Copy constructor
    PmergeMe& operator= (const PmergeMe& copy); //Copy assignment constructor
    void            makePairs();
    void            sortPairs();
    void            insertion(bool);
    int             getJacobstalNumber();
    Container       fordJohnsonAlgorithm(bool);
    ~PmergeMe(); // Destructor

private:
    Container   _input;
    Pairs       _pairs;
    Container   _sorted;
    Container   _pend;
};

template <typename T>
void printContainer(const T& container) {
    typedef typename T::value_type ValueType;
    std::copy(container.begin(), container.end(), std::ostream_iterator<ValueType>(std::cout, " "));
    std::cout << std::endl;
}

template <typename Pairs>
void printPairs(const Pairs& container) {
    typedef typename Pairs::const_iterator ConstIterator; // Define o tipo do iterador
    
    for (ConstIterator it = container.begin(); it != container.end(); ++it) {
        std::cout << "(" << it->first << ", " << it->second << ")" << std::endl;
    }
}

//partition puts all numbers smaller then or equal to pivot to its left and bigger to its right
//returns the index where pivot was placed
template <typename Pairs>
int partition(Pairs& pairs, int low, int high) {
    int pivot = pairs[high].first; // Escolhe o último elemento como pivô
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (pairs[j].first <= pivot) {
            // movendo elementos menores que o pivô para a esquerda
            ++i;
            std::swap(pairs[i], pairs[j]); 
        }
    }
    //Após completar o loop, troca o pivô com o elemento imediatamente após o último elemento menor que o pivô
    std::swap(pairs[i + 1], pairs[high]);
    return i + 1;
}

//quicksort_pair will sort the pairs by the first of each pair (highest value of the pair)
//It's a Divide and Conquer algorithm that picks the last element as a pivot and partitions 
//the given vector around it by placing the pivot in its correct position in the sorted vec.
template <typename Pairs>
void quicksort_pair(Pairs& vec, int low, int high) {
    if (low < high) {
        int index_pivot = partition(vec, low, high);

        quicksort_pair(vec, low, index_pivot - 1);
        quicksort_pair(vec, index_pivot + 1, high);
    }
}

template <typename Container>
PmergeMe<Container>::PmergeMe() {}

template <typename Container>
PmergeMe<Container>::PmergeMe(const Container& input) {
    _input = input;
}

// Copy constructor
template <typename Container>
PmergeMe<Container>::PmergeMe(const PmergeMe& copy) {
    _input = copy._input;
    _pairs = copy._pairs; 
    _sorted = copy._sorted;
    _pend = copy._pend;
}

// Copy assignment operator overload
template <typename Container>
PmergeMe<Container>& PmergeMe<Container>::operator= (const PmergeMe<Container>& copy) {
    // Self-assignment check
    if (this == &copy)
        return *this;
    _input = copy._input;
    _pairs = copy._pairs; 
    _sorted = copy._sorted;
    _pend = copy._pend;
    return *this;
}

template <typename Container>
void  PmergeMe<Container>::makePairs(){
    for (typename Container::iterator it = _input.begin(); it != _input.end(); ++it){
        if(it + 1 == _input.end())
            _pairs.push_back(std::make_pair(0, *it)); //zero means empty
        else{
            _pairs.push_back(std::make_pair(*it, *(it + 1)));
            ++it;
        }
    }
}

template <typename Container>
void  PmergeMe<Container>::sortPairs(){
    for (typename Pairs::iterator it = _pairs.begin(); it != _pairs.end() && it->first != 0; ++it){
        if(it->second > it->first) //zero means empty
            std::swap(it->first, it->second);
    }
}

//returns the next number in the jacobstal sequence, starting at 3
template <typename Container>
int PmergeMe<Container>::getJacobstalNumber(){
    static int before_number = 1;
    static int number = 1;
    int result = number + 2 * before_number;
    before_number = number;
    number = result;
    return result;
}

/*std::lower_bound returns an iterator pointing to the first element in the range that is not less than the specified value. 
If all elements in the range are less than the specified value, it returns an iterator pointing to the end of the range.*/
//Usa std::lower_bound para encontrar a posição de inserção
//Insere o target na posição correta

//starting index to insert = sequencia de jacobstal - 1; 
//insertion area size = 2^x -1 (x comeca no 2, sequencia de jacobstal comeca no 3, ou seja starting index to insert comeca no 2)
template <typename Container>
void PmergeMe<Container>::insertion(bool print){
    for (typename Pairs::iterator it = _pairs.begin(); it != _pairs.end() && it->first != 0; ++it){
        _sorted.push_back(it->first);
    }
    for (typename Pairs::iterator it = _pairs.begin(); it != _pairs.end(); ++it){
        _pend.push_back(it->second);
    }
    if(print == true){
        std::cout << GREEN << "\nStep 4. " << RESET << "Highest numbers of each pair are a sorted sequence:\n";
        printContainer(_sorted);
        std::cout << GREEN << "\nStep 4. " << RESET << "Lowest numbers of each pair are a unsorted sequence:\n";
        printContainer(_pend);
        std::cout << std::endl;
    }
    _sorted.insert(_sorted.begin(), _pend[0]);
    if(print == true){
        std::cout << GREEN << "Step 5. " << RESET << "Insert the numbers in the unsorted sequence (pend) into the sorted sequence (S):\n\n";
        std::cout << GREEN << "Step 5.1. " << RESET << "Insert the fisrt number of pend in the begining of S:\n";
        std::cout << GREEN << "Explanation: " << RESET << "The fisrt number of pend is smaller then the first number of S (and therefore smaller then every number in S):\n";
        printContainer(_sorted);
    }
    int last_starting_index = 0;
    int x = 2;
    while(last_starting_index < static_cast<int>(_pend.size()) - 1){
        int insertion_area_size = std::min(static_cast<int>(std::pow(2, x++)) - 1, static_cast<int>(_sorted.size()));
        int starting_index = std::min(this->getJacobstalNumber() - 1, static_cast<int>(_pend.size()) - 1);
        for(int j = starting_index; j > last_starting_index; --j){
            typename Container::iterator it = std::lower_bound(_sorted.begin(), _sorted.begin() + insertion_area_size, _pend[j]);
            _sorted.insert(it, _pend[j]);
        }
        last_starting_index = starting_index;
    }
}

template <typename Container>
Container PmergeMe<Container>::fordJohnsonAlgorithm(bool print){
    this->makePairs();
    if(print == true){
        std::cout << GREEN << "Step 1. " << RESET << "Make pairs (randomly):\n";
        printPairs(_pairs);
        std::cout << std::endl;
    }
    this->sortPairs();
    if(print == true){
        std::cout << GREEN << "Step 2. " << RESET << "Sort pairs (highest of each pair to the left):\n";
        printPairs(_pairs);
        std::cout << std::endl;
    }
    if(_pairs[_pairs.size() - 1].first == 0)
        quicksort_pair(_pairs, 0, _pairs.size() - 2);
    else
        quicksort_pair(_pairs, 0, _pairs.size() - 1);
    if(print == true){
        std::cout << GREEN << "\nStep 3. " << RESET << "Recursively sort pair container by the highest value of each pair:\n";
        printPairs(_pairs);
        std::cout << std::endl;
    }
    this->insertion(print);
    return _sorted;
}

template <typename Container>
PmergeMe<Container>::~PmergeMe() {}

#endif // PMERGEME_HPP
