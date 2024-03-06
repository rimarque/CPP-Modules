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
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define PURPLE "\033[1;35m"
# define YELLOW "\033[1;33m"
# define WHITE 	"\033[1;37m"
# define CYAN "\033[1;36m"
# define RESET "\033[0m"

//Create my first class in Orthodox Canonical Form
//width - numer of bits used as a whole
class Fixed {

private:
    int                 _fixedPoint;        //store the fixed point value
    static const int    _fractionalBits = 8; //number of fractional bits OU //binary point position 
public:
    Fixed();  //Default Constructor
    Fixed(const Fixed& copy);//Copy constructor
    Fixed& operator= (const Fixed& copy); //Copy assignment constructor
    ~Fixed(void); //Destructor
    int getRawBits( void ) const;
    void setRawBits( int const raw);
};


#endif