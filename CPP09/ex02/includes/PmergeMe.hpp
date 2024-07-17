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
# include <cmath> //para o power of
#include  <algorithm> //para o std::min
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

//Transformar class em template
template <typename Container>
class PmergeMe {
public:
    PmergeMe(); // Constructor
    PmergeMe(const Container& input);
    PmergeMe(const PmergeMe& copy);//Copy constructor
    PmergeMe& operator= (const PmergeMe& copy); //Copy assignment constructor
    void    makePairs();
    void    sortPairs();
    void    insertion();
    T       fordJohnson();
    ~PmergeMe(); // Destructor

private:
    Container                               _input;
    typename Container::template rebind<std::pair<int, int>>::other _pairs;
    Container                               _sorted;
    Container                               _pend;
};

#include "../PmergeMe.cpp"

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

#endif // PMERGEME_HPP
