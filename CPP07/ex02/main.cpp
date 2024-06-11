#include "Array.hpp"

#define MAX_VAL 750

class A{
    public:
        A(): _n(0), _name("empty"), _f(0), _ptr(NULL){};
        A(int n, std::string name, float f, void *ptr): _n(n), _name(name), _f(f), _ptr(ptr){};
        int& getN() {return _n;};
        float& getF() {return _f;};
        void *getPtr() {return _ptr;};
        std::string& getName() {return _name;};
        void setName(const std::string name){_name  = name;};
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

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }
    //std::cout << "uiiii2" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        std::cout << CYAN << "-------Acessing index -2: \n"
        << RESET;
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << CYAN << "-------Acessing index MAX_VAL: \n"
        << RESET;
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    try{
        std::cout << CYAN << "-------Printing index 8: \n" << RESET;
        std::cout << numbers[8] << std::endl;
    }
    catch(std::exception& e){
        std::cout << e.what() << std::endl;
    }
    try{
		const Array<int> test;
		std::cout << CYAN << "\n-------Const instance test (size 0): \n"
        << RESET << test[0] << std::endl;
		//test[0] = 1;
    }
    catch(std::exception& e){
        std::cerr << e.what() << std::endl;
    }
    try{
		const Array<int> test(5);
		std::cout << CYAN << "\n-------Const instance test (size 5): \n"
        << RESET << test[0] << std::endl;
		//test[0] = 1;
    }
    catch(std::exception& e){
        std::cerr << e.what() << std::endl;
    }
    try{
        Array<A> test_class;
        std::cout << CYAN << "\n-------Creating empty array of class A: \n" 
        << RESET << test_class[0] << std::endl;
    }
    catch(std::exception& e){
        std::cerr << e.what() << std::endl;
    }
    try{
        Array<A> test_class(10);
        std::cout << CYAN << "\n-------Creating array of class A (size 10): \n" 
        << RESET << test_class[7] << std::endl;
        test_class[7].setName("look the name has change!");
        std::cout << test_class[7] << std::endl;
    }
    catch(std::exception& e){
        std::cerr << e.what() << std::endl;
    }
    delete [] mirror;//
    return 0;
}