/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:42:08 by rita              #+#    #+#             */
/*   Updated: 2024/03/06 15:19:23 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Point.hpp"

//passar de fixed para float
std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return(out);
}

int main( void ) 
{
	Point a;
	
	std::cout << a.
    return 0;
}
