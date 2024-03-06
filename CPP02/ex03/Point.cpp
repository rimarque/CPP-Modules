/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:34:25 by rita              #+#    #+#             */
/*   Updated: 2024/03/06 15:25:06 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point()
{
    std::cout << "Default Point constructor called" << std::endl;
}

//Copy constructor
Point::Point(const Point& copy){
    (Fixed)_x = copy._x;
    (Fixed)_y = copy._y;
    std::cout << "Copy Point constructor called" << std::endl;
    return ;
}

//Copy assignment operator overload
Point& Point::operator= (const Point& copy)
{
    // self-assignment check
    if(this == &copy)
        return *this;
    (Fixed)_x = copy._x;
    (Fixed)_y = copy._y;
    std::cout << "Copy Point assignment operator overload" << std::endl;
    return (*this);
}

//returns the Fixed_x
int Point::getFixed_x( void ) const
{
    std::cout << "getFixed_x(member function called" << std::endl;
    return(this->_fixedPointValue);
}

//sets the Fixed_x
void Point::setFixed_x( int const raw)
{
    this->_fixedPointValue = raw;
    std::cout << "setRawBits member function called" << std::endl;
}

//returns the Fixed_y
int Point::getFixed_y( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return(this->_fixedPointValue);
}

//sets the Fixed_y
void Point::setFixed_x( int const raw)
{
    this->_fixedPointValue = raw;
    std::cout << "setRawBits member function called" << std::endl;
}

Point::~Point()
{
    std::cout << "Default Point destructor called" << std::endl;
}

