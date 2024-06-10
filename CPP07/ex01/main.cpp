#include "iter.hpp"

class A{
    public:
        A(): _n(0), _name("empty"), _f(0), _ptr(NULL){};
        A(int n, std::string name, float f, void *ptr): _n(n), _name(name), _f(f), _ptr(ptr){};
        int& getN() {return _n;};
        float& getF() {return _f;};
        void *getPtr() {return _ptr;};
        std::string& getName() {return _name;};
        ~A(){};
    private:
        int         _n;
        std::string _name;
        float       _f;
        void        *_ptr;
};

//overload do << operator
std::ostream&       operator<<(std::ostream& out, A& src)
{
    out << "n: " << src.getN() << ", " << "name: " << src.getName() << ", "
    << "float: " << src.getF() << ", " << "ptr: " << src.getPtr();
    return(out);
}

/* Your iter function template must work with any type of array. 
The third parameter can be an instantiated function template. */

int main( void ) {
    std::cout << CYAN << "\n-------Testing int" << RESET << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    ::iter(intArray, ARRAY_SIZE(intArray), printArray<int>);

    std::cout << CYAN << "\n\n-------Testing double" << RESET << std::endl;
    double doubleArray[] = {1.2, 2.0, 3.99, 0.4, -513.6};
    ::iter(doubleArray, ARRAY_SIZE(doubleArray), printArray<double>);

    std::cout << CYAN << "\n\n-------Testing string" << RESET << std::endl;
    std::string stringArray[] = {"1", "2", "3", "4", "1234"};
    ::iter(stringArray, ARRAY_SIZE(stringArray), printArray<std::string>);

    std::cout << CYAN << "\n\n-------Testing class A" << RESET << std::endl;
    char *p = new char;
    void *nu = NULL;
    A classAArray[] = {A(10, "rita", 0.45, p), A(712917, "joan", 1.43, p), A(1, "unknown", -0.9, nu), A()};
    ::iter(classAArray, ARRAY_SIZE(classAArray), printArray<A>);
    std::cout << std::endl;
    delete p;
    return 0;
}