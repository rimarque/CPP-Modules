/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:34:25 by rita              #+#    #+#             */
/*   Updated: 2024/03/08 14:45:42 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Point.hpp"

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    std::cout << "overload operator '<<' caled" << std::endl; 
    out << fixed.toFloat();
    return(out);
}

Point::Point()
{
    std::cout << "Default Point constructor called" << std::endl;
}

//Copy constructor
Point::Point(const Point& copy){
    const_cast<Fixed&>(_x) = copy._x;
    const_cast<Fixed&>(_y) = copy._y;
    std::cout << "Copy Point constructor called" << std::endl;
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
    std::cout << "Copy Point assignment operator overload" << std::endl;
    return (*this);
}

//returns the Fixed_x
Fixed Point::getFixed_x( void ) const
{
    std::cout << "getFixed_x member function called" << std::endl;
    return(_x); //aqui ele chama o copy fixed constructer, porque estamos a construir um novo objeto do tipo fixed, a partir do objeto fixed _x
}

//returns the Fixed_y
Fixed Point::getFixed_y( void ) const
{
    std::cout << "getFixed_y member function called" << std::endl;
    return(_y);
}

//sets the Fixed_x
void Point::setFixed_x(Fixed const fixedN)
{
    const_cast<Fixed&>(_x) = fixedN;
    std::cout << "setFixed_x member function called" << std::endl;
}

//sets the Fixed_y
void Point::setFixed_y(Fixed const fixedN)
{
    const_cast<Fixed&>(_y) = fixedN;
    std::cout << "setFixed_y member function called" << std::endl;
}

//sets _y & _x
void Point::setFixed(Fixed const fixedX, Fixed const fixedY)
{
    const_cast<Fixed&>(_x) = fixedX;
    const_cast<Fixed&>(_y) = fixedY;
    std::cout << "setFixed member function called" << std::endl;
}

/* Fixed    Point::getTriangleArea(Point const a, Point const b, Point const c)
{
    Fixed area = (a._x*(b._y - c._y ) +
                     b._x*(c._y - a._y) + 
                        c._x*(a._y - b._y)) / Fixed(2);
    if (area < 0)
        area = area * Fixed(-1);
    return area;
} */
Fixed Point::getTriangleArea(Point const a, Point const b, Point const c)
{
    // Calcula os produtos mantendo mais bits durante o cálculo
    Fixed term1 = Fixed(a._x) * (b._y - c._y);
    Fixed term2 = Fixed(b._x) * (c._y - a._y);
    Fixed term3 = Fixed(c._x) * (a._y - b._y);

    // Soma os produtos mantendo mais bits durante o cálculo
    Fixed area = (term1 + term2 + term3) / Fixed(2);

    if (area < 0)
        area = area * Fixed(-1); // Não é necessário multiplicar por -1, pois o tipo Fixed já pode lidar com isso diretamente

    return area;
}


Point::~Point()
{
    std::cout << "Point destructor called" << std::endl;
}

