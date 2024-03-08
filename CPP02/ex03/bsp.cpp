/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:48:57 by rita              #+#    #+#             */
/*   Updated: 2024/03/08 16:11:17 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed area;
    Fixed area1;
    Fixed area2;
    Fixed area3;
    
    area = Point::getTriangleArea(a, b, c);
    if(area == 0)
        return(false);
    area1 = Point::getTriangleArea(a, b, point);
    area2 = Point::getTriangleArea(a, point, c);
    area3 = Point::getTriangleArea(point, b, c);
    std::cout << "area do triangulo: " << area << std::endl; 
    std::cout << "area 1, 2 e 3: " << area1 + area2 + area3 << std::endl;
    std::cout << "area 1 " << area1 << std::endl;
    std::cout << "area 2: " << area2 << std::endl;
    std::cout << "area 3: " << area3 << std::endl;
    float area1_tocompare = roundf(area1.toFloat() * 100.0) / 100.0;
    float area2_tocompare = roundf(area2.toFloat() * 100.0) / 100.0;
    float area3_tocompare = roundf(area2.toFloat() * 100.0) / 100.0;
    if(area1_tocompare == 0 || area2_tocompare == 0 || area3_tocompare == 0)
    {
        std::cout << "Ups, está na aresta ou vertice!\n";
        return(false);
    }
    Fixed sum = area1 + area2 + area3;
    float area_tocompare = roundf(area.toFloat() * 100.0) / 100.0;
    float sum_tocompare = roundf(sum.toFloat() * 100.0) / 100.0;
    std::cout << "area to compare do triangulo: " << area_tocompare << std::endl; 
    std::cout << "sum to compare 1, 2 e 3: " << sum_tocompare << std::endl;
    if(area_tocompare == sum_tocompare)
        return(true);
    std::cout << "Ups, está fora!n";
    return(false);
}
