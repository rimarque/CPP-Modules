/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:48:57 by rita              #+#    #+#             */
/*   Updated: 2024/03/11 11:17:21 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Point.hpp"

float   roundTwoDecimalPlaces(float number)
{
    return roundf(number * 100.0) / 100.0;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed area;

    area = Point::getTriangleArea(a, b, c);
    if(roundTwoDecimalPlaces(area.toFloat()) == 0)
        return(false);
    Fixed area1 = Point::getTriangleArea(a, b, point);
    Fixed area2 = Point::getTriangleArea(a, point, c);
    Fixed area3 = Point::getTriangleArea(point, b, c);
    if(roundTwoDecimalPlaces(area1.toFloat()) == 0 || 
        roundTwoDecimalPlaces(area2.toFloat())== 0 ||
            roundTwoDecimalPlaces(area3.toFloat())== 0)
                return(false);
    Fixed sum = area1 + area2 + area3;
    if(roundTwoDecimalPlaces(area.toFloat()) == roundTwoDecimalPlaces(sum.toFloat()))
        return(true);
    return(false);
}
