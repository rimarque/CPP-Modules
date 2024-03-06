/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:59:05 by rita              #+#    #+#             */
/*   Updated: 2024/03/05 15:46:37 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Fixed.hpp"

//*1 << _fractionalBits == (2^_fractionalBits) == 256,
//*se _fractionalBits = 8;

Fixed::Fixed(){
    _fixedPointValue = 0;
    std::cout << "Default constructor called" << std::endl;
    return ;
}

//Copy constructor
Fixed::Fixed(const Fixed& copy){ //const reference
    _fixedPointValue = copy._fixedPointValue;
    std::cout << "Copy constructor called" << std::endl;
    return ;
}

//int -> fixed.point 
//shiftar 8 bits para a esquerda (<< 8) ou * 256
Fixed::Fixed(const int number)
{
    int x;
    
    x = number << _fractionalBits; 
    this->_fixedPointValue = x;
    std::cout << "Int constructor called" << std::endl;
    return ;
}

//float -> fixed.point
//shiftar 8 bits para a esquerda * (1 << _fractionalBits) ou * 256
//roundf -> devolve-te o numero inteiro mais próximo
Fixed::Fixed(const float number)
{
    float x;
    
    x = number * 256;
    x = roundf(x);
    this->_fixedPointValue = (int)x;
    std::cout << "Float constructor called" << std::endl;
    return ;
}

//Copy assignment operator overload
Fixed& Fixed::operator= (const Fixed& copy)
{
    // self-assignment check
    if(this == &copy)
        return *this;
    _fixedPointValue = copy._fixedPointValue;
    std::cout << "Copy assignment operator overload" << std::endl;
    return (*this);
}

//returns the raw value of the fixed-point value
int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return(this->_fixedPointValue);
}

    //sets the raw value of the fixed-point number.
void Fixed::setRawBits( int const raw)
{
    this->_fixedPointValue = raw;
    std::cout << "setRawBits member function called" << std::endl;
}

//fixed_point -> float
// / (1 << _fractionalBits) ou / 256
float   Fixed::toFloat(void) const
{
    return((float)this->_fixedPointValue / 256);
}

//fixed_point -> int
// / (1 << _fractionalBits) ou / 256
int   Fixed::toInt(void) const
{
    return((int)this->_fixedPointValue / 256);
}

//Comparison operators
bool    Fixed::operator> (const Fixed& compare) const
{
    std::cout << "Comparison operator overload '>' called" << std::endl;
    return(this->_fixedPointValue > compare._fixedPointValue);
}

bool    Fixed::operator< (const Fixed& compare) const
{
    std::cout << "Comparison operator overload'<' called" << std::endl;
    return(this->_fixedPointValue < compare._fixedPointValue); 
}

bool    Fixed::operator>= (const Fixed& compare) const
{
    std::cout << "Comparison operator overload'>=' called" << std::endl;
    return(this->_fixedPointValue >= compare._fixedPointValue); 
}

bool    Fixed::operator<= (const Fixed& compare) const
{
    std::cout << "Comparison operator overload'<=' called" << std::endl;
    return(this->_fixedPointValue <= compare._fixedPointValue);
}

bool    Fixed::operator== (const Fixed& compare) const
{
    std::cout << "Comparison operator overload'==' called" << std::endl;
    return(this->_fixedPointValue == compare._fixedPointValue);
}

bool    Fixed::operator!= (const Fixed& compare) const
{
    std::cout << "Comparison operator overload'!=' called" << std::endl;
    return(this->_fixedPointValue <= compare._fixedPointValue);
}

//Aritmetic operators
Fixed Fixed::operator+ (const Fixed& copy) const
{
    Fixed result;
    std::cout << "Aritmetic '+' operator overload called" << std::endl;
    result._fixedPointValue = _fixedPointValue + copy._fixedPointValue;
    return result;
}

Fixed Fixed::operator- (const Fixed& copy) const
{
    Fixed result;

    std::cout << "Aritmetic '-' operator overload called" << std::endl;
    result._fixedPointValue = _fixedPointValue - copy._fixedPointValue;
    return result;
}

// / (1 << _fractionalBits) ou / 256
Fixed Fixed::operator* (const Fixed& copy) const
{
    Fixed result;
    
    std::cout << "Aritmetic '*' operator overload called" << std::endl;
    //Perform multiplication using a larger integer type to prevent overflow
    long long product = (_fixedPointValue * copy._fixedPointValue);
    result._fixedPointValue = product / 256;
    return result;
}

//(_fixedPointValue << _fractionalBits) ou * (1 << _fractionalBits) ou * 256
Fixed Fixed::operator/ (const Fixed& copy) const
{
    Fixed result;

    std::cout << "Aritmetic '/' operator overload called" << std::endl;
    result._fixedPointValue = (_fixedPointValue * 256) / copy._fixedPointValue;
    return result;
}

//Increment/decrement operators
Fixed    Fixed::operator++ () //++i
{
    std::cout << "'Pre Increment' operator overload called" << std::endl;
    ++_fixedPointValue;
    return (*this);
}

Fixed    Fixed::operator-- () //--i
{
    std::cout << "'Pre decrement' operator overload called" << std::endl;
    --_fixedPointValue;
    return (*this);
}

Fixed    Fixed::operator++ (int) //i++
{
    Fixed   copy;
    std::cout << "'Pos Increment' operator overload called" << std::endl;
    copy._fixedPointValue = _fixedPointValue++;
    return (copy);
}

Fixed    Fixed::operator-- (int) //i--
{
    Fixed   copy;

    std::cout << "'Pro decrement' operator overload called" << std::endl;
    copy._fixedPointValue = _fixedPointValue--;
    return (copy);     
}

//Add these four public overloaded member functions to your class:
Fixed&  Fixed::min(Fixed& a, Fixed& b) //retorna o mais pequeno
{   
    std::cout << "min function called" << std::endl;
    if(a.getRawBits() < b.getRawBits())
        return(a);
    return(b);
}

//basta um dos parametros ser const para set esta a funçao chamada
const Fixed&    Fixed::min(const Fixed& a, const Fixed& b) //retorna referencia ao mais pequeno
{
    std::cout << "const min function called" << std::endl;
    if(a.getRawBits() < b.getRawBits())
        return(a);
    return(b);
}
Fixed&  Fixed::max(Fixed& a, Fixed& b) //retorna o maior
{
    std::cout << "max function called" << std::endl;
    if(a.getRawBits() > b.getRawBits())
        return(a);
    return(b);
}

const Fixed&  Fixed::max(const Fixed& a, const Fixed& b) //retorna referencia ao maior
{
    std::cout << "const max function called" << std::endl;
    if(a.getRawBits() > b.getRawBits())
        return(a);
    return(b);
}

Fixed::~Fixed(){
    std::cout << "Destructor caled" << std::endl;
    return ;
}