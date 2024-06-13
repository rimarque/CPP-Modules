#include "includes/Span.hpp"

Span::Span(): _maxN(0){
    /* std::cout << BOLD_WHITE << "Span" << RESET 
    << " default constructor called" << std::endl; */
}

Span::Span(unsigned int n): _maxN(n){
/*     std::cout << BOLD_WHITE << "Span" << RESET 
    << " max N constructor called with max n = " << _maxN << std::endl; */
}

// Copy constructor
Span::Span(const Span& copy)
    : 
        _maxN(copy._maxN), 
        _vec(copy._vec)
{
    // Copy stuff
/*     std::cout << BOLD_WHITE << "Span" << RESET 
    << " copy constructor called" << std::endl; */
}

// Copy assignment operator overload
Span& Span::operator= (const Span& copy) {
    // Self-assignment check
    if (this == &copy)
        return *this;
    _maxN = copy._maxN;
    _vec = copy._vec;
/*     std::cout << BOLD_WHITE << "Span" << RESET 
    << " copy assignment operator overload" << std::endl;*/
    return *this;
}

//Getter
std::vector<int> Span::getVec() const{
    return _vec;
}

//Metods
void    Span::addNumber(int n){
        if(_vec.size() == _maxN)
            throw std::overflow_error("The container is full");
        _vec.push_back(n);
} //add a single number to the span

int     Span::shortestSpan() const{
    if (_vec.size() < 2){
        throw std::logic_error("Not enough numbers to find a span");
    }
    std::vector<int> copy_vec(_vec);
    std::sort(copy_vec.begin(), copy_vec.begin());
    unsigned int shortest_span = std::numeric_limits<unsigned int>::max();;
    unsigned int current_span;
    for (unsigned int i = 0; i < _vec.size() - 1; i++){
        current_span =  copy_vec[i + 1] - copy_vec[i];
        if(current_span < shortest_span)
            shortest_span = current_span;
    }
    return shortest_span;
}//diferença mais pequena entre 2 numeros

int     Span::longestSpan() const{
    if (_vec.size() < 2){
        throw std::logic_error("Not enough numbers to find a span");
    }
    int min = *std::min_element(_vec.begin(), _vec.end());
    int max = *std::max_element(_vec.begin(), _vec.end());
    return max - min;
}//diferença maior entre 2 numeros

Span::~Span() {
/*     std::cout << BOLD_WHITE << "Span" << RESET 
    << " destructor called" << std::endl; */
}
