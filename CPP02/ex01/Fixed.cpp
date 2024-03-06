/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:59:05 by rita              #+#    #+#             */
/*   Updated: 2024/03/05 12:08:16 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Fixed.hpp"

//256 = (2^_fractionalBits), 
//tal que _fractionalBits é sempre = 8;
//equivalente a: (1 << this->_fractionalBits) = 1 << 8;
//que shifta 8 bits para a esquerda
//1 << _fractionalBits == (2^_fractionalBits)

Fixed::Fixed(){
    _fixedPoint = 0;
    std::cout << "Default constructor called" << std::endl;
    return ;
}

//Copy constructor
Fixed::Fixed(const Fixed& copy){ //const reference
    _fixedPoint = copy._fixedPoint;
    std::cout << "Copy constructor called" << std::endl;
    return ;
}

Fixed::Fixed(const int number)
{
    int x;
    
    x = number << _fractionalBits; 
    this->_fixedPoint = x;
    std::cout << "Int constructor called" << std::endl;
    return ;
}

Fixed::Fixed(const float number)
{
    float x;
    
    x = number * 256;
    x = roundf(x);
    this->_fixedPoint = (int)x;
    std::cout << "Float constructor called" << std::endl;
    return ;
}

Fixed& Fixed::operator= (const Fixed& copy)
{
    // self-assignment check
    if(this == &copy)
        return *this;
    _fixedPoint = copy._fixedPoint;
    std::cout << "Copy assignment operator overload" << std::endl;
    return (*this);
}

Fixed::~Fixed(){
    std::cout << "Destructor caled" << std::endl;
    return ;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return(this->_fixedPoint);
}

void Fixed::setRawBits( int const raw)
{
    this->_fixedPoint = raw;
    std::cout << "setRawBits member function called" << std::endl;
}

float   Fixed::toFloat(void) const
{
    return((float)this->_fixedPoint / 256);
}

int   Fixed::toInt(void) const
{
    return((int)this->_fixedPoint / 256);
}