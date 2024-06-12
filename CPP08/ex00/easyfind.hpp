#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <stdexcept>
# include <vector>
# include <deque>
# include <list>
# include <iostream>
# include <iterator> // Include for std::ostream_iterator
# define CYAN "\033[36m"
# define RESET "\033[0m"

//Assuming T is a container of intergers
//returns a pointer to the firt occurence in a container
template <typename T>
typename T::iterator easyfind(T& container, int occurrence){
    // std::find: is STL algothim that returns an iterator(pointer) to the 
    //first occurence of the specified element in the sequence
    typename T::iterator it = 
        std::find(container.begin(), container.end(), occurrence);
    if(it == container.end())
        throw std::runtime_error("Occurrence not found");
    return it;
}

template <typename T>
void printContainer(const T& container) {
    typedef typename T::value_type ValueType;
    std::copy(container.begin(), container.end(), std::ostream_iterator<ValueType>(std::cout, " "));
    std::cout << std::endl;
}


#endif