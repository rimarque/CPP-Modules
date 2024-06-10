#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
# define CYAN "\033[36m"
# define RESET "\033[0m"
# define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

template <typename T>
class Array{
    public:
        Array(): _array(NULL), _size(0) {};
        Array(unsigned int n): _size(n){_array = new T[_size];}; //no sure
        Array(const Array& copy): _size(copy._size){
            //std::cout << "copy constructor called with size: " << copy._size << "\n";
            _array = new T[copy._size];
            for(unsigned int i = 0; i < copy._size;i++){
                    _array[i] = copy._array[i];
                }
        };
        Array& operator=(const Array& copy){
            //std::cout << "copy op called\n";
             _size = copy._size;
            if (this == &copy)
                return *this;
            delete[] _array;
            _array = new T[copy._size];
            for(unsigned int i = 0; i < copy._size;i++){
                    _array[i] = copy._array[i];
            }
            return *this;
        };
        T   operator[](unsigned int i) const{ //read only
            std::cout << "read only op called\n";
            if(i >= _size)
                throw std::out_of_range("Index out of bounds");
            return _array[i];
        };
        T&    operator[](unsigned int i){ //modify
            //std::cout << "modify op called\n";
            //std::cout << i << ", " << _size << std::endl;
            if(i >= _size)
                throw std::out_of_range("Index out of bounds");
            return _array[i];
        };
        int size() const{
            return _size;
        };
        ~Array() { delete[] _array;};
    private:
        T           *_array;
        unsigned int _size;
};


#endif