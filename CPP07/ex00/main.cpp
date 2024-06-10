#include "templates.hpp"

class A{
    public:
        A(): _a(0){};
        A(int a): _a(a){};
        int getA() const {return _a;};
        bool operator>( A const & src ) const { return (this->_a> src._a); }
        bool operator<( A const & src ) const { return (this->_a< src._a); }
        ~A(){};
    private:
        int _a;
};

std::ostream & operator<<(std::ostream & o, const A &a) { o << a.getA(); return o; }

/* These functions can be called with any type of argument. 
The only requirement is that the two arguments must have 
the same type and must support all the comparison operators. */

int main( void ) {
    std::cout << CYAN << "-------Testing int" << RESET << std::endl;
    int a = 2;
    int b = 3;
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

    std::cout << CYAN << "-------Testing string" << RESET << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

    std::cout << CYAN << "-------Testing class A" << RESET << std::endl;
    A class_test1;
    A class_test2(1);
    ::swap( class_test1, class_test2 );
    std::cout << "class_test1 = " << class_test1 << ", class_test2 = " << class_test2 << std::endl;
    std::cout << "min( class_test1 _a, class_test2 _a ) = " << ::min( class_test1, class_test2 ) << std::endl;
    std::cout << "max( class_test1 _a, class_test2 _a) = " << ::max( class_test1, class_test2 ) << std::endl;
    return 0;
}