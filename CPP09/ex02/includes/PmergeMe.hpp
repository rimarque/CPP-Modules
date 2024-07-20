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
            //Move os elementos menores que o pivô para a esquerda, trocando o pairs[j] com o numero mais a esquerda que e maior que o pivo: pairs[i]
            ++i;
            std::swap(pairs[i], pairs[j]); 
        }
    }
    //Após completar o loop, troca o pivo, pairs[high], com o numero mais a esquerda que e maior que o pivo, pairs[i]
    std::swap(pairs[++i], pairs[high]);
    return i;
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

//makePairs creates a std::pair<int, int> container, paring random numbers from the original int container
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

//sortPairs puts the highest numner of each pair has the first of each pair
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

//Insertion creates 2 containers: sorted (from the first number of each pair) and pend (wicth is not sorted, from the second number of each pair)
//It's goal is to insert, one by one, the numbers in pend into sorted, getting, in the end, the sorted sequence with all the numbers (final output of the algorithm)

//Note that sorted has the first and highest numbers of each pair
//We will use notation like p1, p2, p3 to describe the numbers in pend, and s1, s2... to describe the numbers in sorted (where p1 and s1 are the first numbers of each sequence)

//The goal of the algorithm is to do the least number of comparisons
//For the worst case scenario we get the least number of comparisons if we try to insert a number into a sequence with size (2^x) - 1 (insertion area)

//The ford jonhson algorithm uses binary search to find the right spot in sorted in witch to insert each element of pend
//The key for this algorithm is in the size of the area of sorted in witch we are searching (insertion area = (2^x) - 1)
//In the code bellow I took - 1 from the indexes choosen because in c++ indexes start at 0 instead of 1

//We know the first number of pend is smaller then the first number of sorted (p1 < s1), so the first step is to insert p1 in the begining of sorted

//Going forward, there is a specific order in which we insert the numbers from the pend sequence into the sorted sequence:
//this link was the one I found that better explains the reasoning behind this order, but the goal of this insertion order is to insert the number into a sequence with size (2^x) - 1 (insertion area)
//https://codereview.stackexchange.com/questions/116367/ford-johnson-merge-insertion-sort

//1. Choose the next index to insert: use the jacobstal sequence (...3, 5, 11, 21, 43, 85...), starting at number 3, to choose the index of the next number to insert
//2. Choose the next insertion area: (2^x)-1, starting at x = 2
//3. Insert the choosen index into the first (2^x)-1 numbers of sorted
        //The first time we will insert p3 into the first 3 numbers of sorted (insertion area = 3)
//4. Go backwards in the pend sequence inserting the numbers one by one into the the first (2^x)-1 numbers of sorted
        //The first time we will insert p2, and then stop, because p1 was already inserted (insertion area = 3)
//When it finds an index witch has already been inserted it reapeats steps 1, 2, 3 and 4
    //Next time the index will be 5, the insertion area will be 7, and we will insert p5 and p4
    //After, the index will be 11, the insertion area will be 15, and we will insert p11, p10, p9, p8, p7, p6

//Example + explanation:
//NOTE: First we insert p1 in the begining of sorted
//1. The first index to insert is 3
//2. The first insertion area is 3
//3. Insert p3 into the first 3 numbers of sorted
        //The size of the insertion area in wicth we need to search to insert p3 is 3 ((2^2) - 1), why?
        //We know p3 is smaller then s3, so we only need to look in {p1, s1, s2}
//4. Insert p2 into the first 3 numbers of sorted
        //The size of the insertion area in wicth we need to search to insert p2 is only 3 ((2^2) - 1), why?
        //We know p2 is smaller then s2, so we only need to look in {p1, s1, p3}, {p1, p3, s1} or {p1, s1, s2}, depending where p3 was inserted

//1. The second index to insert is 11
//2. The second insertion area is 15
//3. Insert p5 into the first 7 numbers of sorted
        //The size of the insertion area in wicth we need to search to insert p5 is 7 ((2^3) - 1), why?
        //We know p5 is smaller then s5, so we only need to look in {p1, s1, p2, p3, s2, s3, s4}
//4. Insert p4 into the first 7 numbers of sorted
        //The size of the insertion area in wicth we need to search to insert p4 is only 7 or less ((2^3) - 1), why?
        //We know p4 is smaller then s4, so we only need to look in {p1, s1, p2, p3, s2, s3, p5}

//1. The thirth index to insert is 5
//2. The thirth insertion area is 7
//3. Insert p11 into the first 15 numbers of sorted
        //The size of the insertion area in wicth we need to search to insert p11 is 15 ((2^4) - 1), why?
        //We know p11 is smaller then s11, so we only need to look in {p1, s1, p2, p3, s2, s3, p5, p4, s4, s5, s6, s7, s8, s9, s10}
//4.1 Insert p10 into the first 15 numbers of sorted
        //The size of the insertion area in wicth we need to search to insert p10 is only 15 ((2^4) - 1), why?
        //We know p10 is smaller then s10, so we only need to look in {p1, s1, p2, p3, s2, s3, p5, p4, s4, s5, s6, s7, s8, s9, p11}
//4.2 Insert p9 into the first 15 numbers of sorted
        //The size of the insertion area in wicth we need to search to insert p9 is only 15 ((2^4) - 1), why?
        //We know p9 is smaller then s9, so we only need to look in {p1, s1, p2, p3, s2, s3, p5, p4, s4, s5, s6, s7, s8, p11, p10}
//4.3 Insert p8 into the first 15 numbers of sorted
        //The size of the insertion area in wicth we need to search to insert p8 is only 15 ((2^4) - 1), why?
        //We know p8 is smaller then s8, so we only need to look in {p1, s1, p2, p3, s2, s3, p5, p4, s4, s5, s6, s7, p11, p10, p9}
//4.4 Insert p7 into the first 15 numbers of sorted
        //The size of the insertion area in wicth we need to search to insert p7 is only 15 ((2^4) - 1), why?
        //We know p7 is smaller then s7, so we only need to look in {p1, s1, p2, p3, s2, s3, p5, p4, s4, s5, s6, p11, p10, p9, p8}
//4.4 Insert p6 into the first 15 numbers of sorted
        //The size of the insertion area in wicth we need to search to insert p6 is only 15 ((2^4) - 1), why?
        //We know p6 is smaller then s6, so we only need to look in {p1, s1, p2, p3, s2, s3, p5, p4, s4, s5, p11, p10, p9, p8, p7}

//1. The fourth index to insert is 21
//2. The fourth insertion area is 31
//3. ...

//We go on like this until all numbers from the pend sequence are inserted into the sorted sequence
//Although the explanation of the insertion varies a litle from mine (also correct, just a slightly different explanation), 
//I found this figma very usefull to understand and visualize the algorithm working:
//https://www.figma.com/board/JW5jFeoD6fbSnu2K2XXfKV/Ford-Johnson-(merge-insertion-sort)-algorithm?node-id=0-1&t=fUrqtORMbTtfKqEL-0

//Insertion uses lower_bound to find the place of insertion in the sorted container
//lower_bound() is used to return the pointer to the first element that is greater than or equal to the value passed. 
//lower_bound() uses binary search to search through the space (binary search is an important part of the ford jonhson algorithm)

//starting index to insert = sequencia de jacobstal - 1 (jacobstal sequence starts at 3)
//insertion area size = 2^x -1 (x starts at 2)
template <typename Container>
void PmergeMe<Container>::insertion(bool print){
    for (typename Pairs::iterator it = _pairs.begin(); it != _pairs.end() && it->first != 0; ++it){
        _sorted.push_back(it->first);
    }
    for (typename Pairs::iterator it = _pairs.begin(); it != _pairs.end(); ++it){
        _pend.push_back(it->second);
    }
    if(print == true){
        std::cout << GREEN << "\nStep 4. " << RESET << "Highest numbers of each pair form a sorted sequence:\nS: ";
        printContainer(_sorted);
        std::cout << GREEN << "\nStep 4. " << RESET << "Lowest numbers of each pair form a unsorted sequence:\npend: ";
        printContainer(_pend);
        std::cout << std::endl;
    }
    _sorted.insert(_sorted.begin(), _pend[0]);
    if(print == true){
        std::cout << GREEN << "Step 5. " << RESET << "Insert the numbers in the unsorted sequence (pend) into the sorted sequence (S):\n\n";
        std::cout << GREEN << "Step 5.1. " << RESET << "Insert the fisrt number of pend in the begining of S:\n";
        std::cout << GREEN << "Explanation: " << RESET << "The fisrt number of pend is smaller then the first number of S (and therefore smaller then every number in S):\n";
        std::cout << "pend: ";
        printContainer(_pend);
        std::cout << "S: ";
        printContainer(_sorted);
        std::cout << std::endl;
        std::cout << GREEN << "Step 5.2. " << RESET << "Going forward, there is a specific order in which we insert the numbers from pend into S.\n"
        << "We use the jacobstal sequence to find the next index to insert. The goal is to insert the number in a subquence of S with size (2^x)-1\n";
        std::cout << std::endl;
    }
    int last_starting_index = 0;
    int x = 2;
    while(last_starting_index < static_cast<int>(_pend.size()) - 1){
        int insertion_area_size = std::min(static_cast<int>(std::pow(2, x++)) - 1, static_cast<int>(_sorted.size()));
        int starting_index = std::min(this->getJacobstalNumber() - 1, static_cast<int>(_pend.size()) - 1);
        if(print == true){
            std::cout << GREEN << "Step 5.2." << x - 2 << ". "<< RESET << "Index to insert: " << starting_index + 1 << "; insertion area: " << insertion_area_size;
            std::cout << std::endl;
        }
        for(int j = starting_index; j > last_starting_index; --j){
            typename Container::iterator it = std::lower_bound(_sorted.begin(), _sorted.begin() + insertion_area_size, _pend[j]);
            _sorted.insert(it, _pend[j]);
            if(print == true){
                std::cout << GREEN << "Insert index " << j + 1 << RESET << std::endl;
                std::cout << "pend: ";
                printContainer(_pend);
                std::cout << "S: ";
                printContainer(_sorted);
            }
        }
        last_starting_index = starting_index;
        if(print == true)
            std::cout << std::endl;
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
