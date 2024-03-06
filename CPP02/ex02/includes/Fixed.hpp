#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <string>
# include <cctype>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <iomanip> 
# include <cstdlib>
# include <ctime>
# include <math.h>
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define PURPLE "\033[1;35m"
# define YELLOW "\033[1;33m"
# define WHITE 	"\033[1;37m"
# define CYAN "\033[1;36m"
# define RESET "\033[0m"

class Fixed {

private:
    //Variable stores the fixed point value
    int                 _fixedPointValue;
    //Number of fractional bits         
    static const int    _fractionalBits = 8;

public:
    //*Constructors
    //Default Constructor
    Fixed();
    //Copy constructor
    Fixed(const Fixed& copy);
    //Copy assignment constructor
    Fixed& operator= (const Fixed& copy);
    //Converts int to fixed point value
    Fixed(const int number); 
    //Converts float to fixed point value
    Fixed(const float number);

    //*Getters & Setters
    //Get fixed point value
    int     getRawBits( void ) const;
    //Set fixed point value
    void    setRawBits( int const raw);

    //*Converts fixed point to ...
    //Converts fixed point value to float
    float   toFloat(void) const;
    //Converts fixed point value to int
    int     toInt( void ) const;

    //*Comparison operators overload
    bool    operator> (const Fixed& compare) const;
    bool    operator< (const Fixed& compare) const;
    bool    operator>= (const Fixed& compare) const;
    bool    operator<= (const Fixed& compare) const;
    bool    operator== (const Fixed& compare) const;
    bool    operator!= (const Fixed& compare) const;

    //*Aritmetic operators overload -> const porque não modifica o fixed
    Fixed operator+ (const Fixed& copy) const;
    Fixed operator- (const Fixed& copy) const;
    Fixed operator* (const Fixed& copy) const;
    Fixed operator/ (const Fixed& copy) const;

    //*Increment/decrement operators overload
    Fixed    operator++ ();     //++i
    Fixed    operator-- ();     //--i
    Fixed    operator++ (int);  //i++
    Fixed    operator-- (int);  //i--

    //*Returns min ou max
    static Fixed&       min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed&       max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);

    //*Destructor
    ~Fixed(void);
};

#endif