#ifndef ITER_HPP
# define ITER_HPP

# include  <iostream>
# define CYAN "\033[36m"
# define RESET "\033[0m"
# define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

template <typename T>
void printArray(T a){
    std::cout << a << ", ";
}

template <typename T, typename F>
void iter(T *a, int n, F f){
    for(int i = 0; i < n; i++){
        f(a[i]);
    }
}

#endif