#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string.h>
# include <unistd.h>
# include <cstdlib>
# include <ctime>
# include <stack>
# include <deque> // default container for std::stack
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


template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:
    typedef typename Container::iterator iterator;
    typedef typename Container::const_iterator const_iterator;
    typedef typename Container::reverse_iterator reverse_iterator;
    typedef typename Container::const_reverse_iterator const_reverse_iterator;

    // Default constructor
    MutantStack() : std::stack<T, Container>() {}

    // Copy constructor
    MutantStack(const MutantStack& other) : std::stack<T, Container>(other) {}

    // Copy assignment operator
    MutantStack& operator=(const MutantStack& other) {
        if (this != &other) {
            std::stack<T, Container>::operator=(other);
        }
        return *this;
    }

       /* The syntax this->c.function() is used to access the end() member function of the underlying container of the std::stack. */
/*     The std::stack class is a container adapter, which means it uses another container. This underlying container is accessible through a protected member variable named c. */

    iterator begin() { return this->c.begin(); }
    
    iterator end() { return this->c.end(); }
    
    const_iterator begin() const { return this->c.begin(); }
    
    const_iterator end() const { return this->c.end(); }
    
    reverse_iterator rbegin() { return this->c.rbegin(); }
    
    reverse_iterator rend() { return this->c.rend(); }
    
    const_reverse_iterator rbegin() const { return this->c.rbegin(); }
    
    const_reverse_iterator rend() const { return this->c.rend(); }

    ~MutantStack() {}
};

#endif // MUTANTSTACK_HPP
