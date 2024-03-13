/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:34:25 by rita              #+#    #+#             */
/*   Updated: 2024/03/11 11:52:41 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Point.hpp"

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return(out);
}

Point::Point()
{
   return ;
}

//Copy constructor
Point::Point(const Point& copy){
    const_cast<Fixed&>(_x) = copy._x;
    const_cast<Fixed&>(_y) = copy._y;
    return ;
}

Point::Point(const float x, const float y)
{
    const_cast<Fixed&>(_x) = Fixed(x);
    const_cast<Fixed&>(_y) = Fixed(y);
}
//Copy assignment operator overload
Point& Point::operator= (const Point& copy)
{
    // self-assignment check
    if(this == &copy)
        return *this;
    const_cast<Fixed&>(_x) = copy._x;
    const_cast<Fixed&>(_y) = copy._y;
    return (*this);
}

//returns the Fixed_x
Fixed Point::getFixed_x( void ) const
{
    return(_x); //aqui ele chama o copy fixed constructer, porque estamos a construir um novo objeto do tipo fixed, a partir do objeto fixed _x
}

//returns the Fixed_y
Fixed Point::getFixed_y( void ) const
{
    return(_y);
}

//sets the Fixed_x
void Point::setFixed_x(Fixed const fixedN)
{
    const_cast<Fixed&>(_x) = fixedN;
}

//sets the Fixed_y
void Point::setFixed_y(Fixed const fixedN)
{
    const_cast<Fixed&>(_y) = fixedN;
}

//sets _y & _x
void Point::setFixed(Fixed const fixedX, Fixed const fixedY)
{
    const_cast<Fixed&>(_x) = fixedX;
    const_cast<Fixed&>(_y) = fixedY;
}
Fixed Point::getTriangleArea(Point const a, Point const b, Point const c)
{
    // Calcula os produtos mantendo mais bits durante o cálculo
    Fixed term1 = Fixed(a._x) * (b._y - c._y);
    Fixed term2 = Fixed(b._x) * (c._y - a._y);
    Fixed term3 = Fixed(c._x) * (a._y - b._y);

    // Soma os produtos mantendo mais bits durante o cálculo
    Fixed area = (term1 + term2 + term3) / Fixed(2);

    if (area < 0)
        area = area * Fixed(-1);

    return area;
}

Point::~Point()
{
    return ;
}
