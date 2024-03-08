/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:42:08 by rita              #+#    #+#             */
/*   Updated: 2024/03/08 16:02:33 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Point.hpp"

//4o Quadrante (y negtivo e x positivo)
//3o Quadrante (y e x negativos)
//2o Quadrante (y positivo e negativo)
//1o Quadrante (y e x positivos)
int main( void ) 
{
	Point a(12.58, 3.53);
    Point b(10.38, 5.41);
    Point c(8.98, 3.63);
    Point pointOutClose(11.84,4.22);
    Point pointOutFar(7.3,5.47);
    Point pointInMidle(10.7,4.13);
    Point pointInPeripheral(9.412,3.823);
    Point pointEdge(11.18829164644,3.5686577173323);
    
    std::cout << "Points outside of triangle: " << "close: " << CYAN << bsp(a, b, c, pointOutClose) << RESET
    << "\nfar: " << CYAN << bsp(a, b, c, pointOutClose) << RESET <<  std::endl;
    std::cout << "Points inside of triangle: " << "midle: " << GREEN << bsp(a, b, c, pointInMidle) << RESET
    << "\nperipheral: " << GREEN << bsp(a, b, c, pointInPeripheral) << RESET << std::endl;
    std::cout << "Point edge of triangle: " << RED << bsp(a, b, c, pointEdge) << RESET << std::endl;
    std::cout << "Point vertix of triangle: " << WHITE <<  bsp(a, b, c, a) << RESET << std::endl;
    return 0;
}

//Main que testa ortodoxal cannonical form e 
/* int main( void ) 
{
	Point a;

	std::cout << CYAN << "a.x is: \n" << RESET;
    std::cout << a.getFixed_x() << std::endl;
    std::cout << CYAN << "a.y is: \n" << RESET;
    std::cout << a.getFixed_y() << std::endl;
    
    a.setFixed_x(Fixed(10.2155f));
    a.setFixed_y(Fixed(5.899f));
    
    Point b(a);

    std::cout << CYAN << "b.x is: \n" << RESET;
    std::cout << b.getFixed_x()<< std::endl;
    std::cout << CYAN << "b.y is: \n" << RESET;
    std::cout << b.getFixed_y() << std::endl;
    
    a.setFixed_x(Fixed(50));
    a.setFixed_y(Fixed(34));

    b = a;
    
    std::cout << CYAN << "b.x is: \n" << RESET;
    std::cout << b.getFixed_x()<< std::endl;
    std::cout << CYAN << "b.y is: \n" << RESET;
    std::cout << b.getFixed_y() << std::endl;
    return 0;
} */
