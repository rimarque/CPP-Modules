/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:59:05 by rita              #+#    #+#             */
/*   Updated: 2024/02/15 13:28:54 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Fixed.hpp"

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

//Copy assignment operator overload
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

    //returns the raw value of the fixed-point value
int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return(this->_fixedPoint);
}

    //sets the raw value of the fixed-point number.
void Fixed::setRawBits( int const raw)
{
    this->_fixedPoint = raw;
    std::cout << "setRawBits member function called" << std::endl;
}