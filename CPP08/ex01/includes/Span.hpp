#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string.h>
# include <unistd.h>
# include <cstdlib>
# include <ctime>
# include <vector>
# include <stdexcept>
# include <algorithm>
# include <limits>
# include <iterator>
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
# define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

class Span {
public:
    //Constructors
    Span();
    Span(unsigned int N);
    Span(const Span& copy);

    //Operators
    Span& operator= (const Span& copy);

    //Getter
    std::vector<int> getVec() const;
    //Metods
    void addNumber(int n);
    template <typename Iterator>
    void    addNumber(Iterator begin, Iterator end) {
        if (_vec.size() + std::distance(begin, end) > _maxN) {
            throw std::overflow_error("The container will be full");
        }
        _vec.insert(_vec.end(), begin, end);
    }
    int shortestSpan() const;//diferença mais pequena entre 2 numeros
    int longestSpan() const;//diferença maior entre 2 numeros
    
    //Destructor
    ~Span();

private:
    unsigned int _maxN;
    std::vector<int> _vec;
};

template <typename T>
void printContainer(const T& container) {
    typedef typename T::value_type ValueType;
    std::copy(container.begin(), container.end(), std::ostream_iterator<ValueType>(std::cout, " "));
    std::cout << std::endl;
}

#endif // SPAN_HPP
