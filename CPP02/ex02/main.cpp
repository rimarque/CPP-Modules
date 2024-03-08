/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:42:08 by rita              #+#    #+#             */
/*   Updated: 2024/03/08 13:51:51 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Fixed.hpp"

//passar de fixed para float
std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return(out);
}

void	info_values(Fixed &a, Fixed &b, Fixed &c, Fixed &d, Fixed &e, Fixed &f, Fixed &g, Fixed &h, Fixed &i, Fixed &test) {
	std::cout << YELLOW << "--------------------INFO--------------------" << RESET << std::endl;
	std::cout << "\ta is: " << a << std::endl;
	std::cout << "\tb is: " << b << std::endl;
	std::cout << "\tc is: " << c << std::endl;
	std::cout << "\td is: " << d << std::endl;
	std::cout << "\te is: " << e << std::endl;
	std::cout << "\tf is: " << f << std::endl;
	std::cout << "\tg is: " << g << std::endl;
	std::cout << "\th is: " << h << std::endl;
	std::cout << "\ti is: " << i << std::endl;
	std::cout << "\ttest is: " << test << std::endl;

	std::cout << std::endl;

	std::cout << "\ta is: " << a.toInt() << " as integer" << std::endl;
	std::cout << "\tb is: " << b.toInt() << " as integer" << std::endl;
	std::cout << "\tc is: " << c.toInt() << " as integer" << std::endl;
	std::cout << "\td is: " << d.toInt() << " as integer" << std::endl;
	std::cout << "\te is: " << e.toInt() << " as integer" << std::endl;
	std::cout << "\tf is: " << f.toInt() << " as integer" << std::endl;
	std::cout << "\tg is: " << g.toInt() << " as integer" << std::endl;
	std::cout << "\th is: " << h.toInt() << " as integer" << std::endl;
	std::cout << "\ti is: " << i.toInt() << " as integer" << std::endl;
	std::cout << YELLOW << "-----------------END-INFO-------------------" << RESET << std::endl;
}

int main() {
	Fixed			a;
	Fixed const		a_cpy;
	Fixed			b ( Fixed( 5.05f ) * Fixed( -2 ));
	Fixed const		b_cpy ( Fixed( 5.05f ) * Fixed( 2 ));
	Fixed			c( -10 );
	Fixed			d( -42.42f );
	Fixed const		d_cpy( 42.42f );
	Fixed			e( c );
	Fixed			f;
	Fixed			g ( Fixed( -234.45f ) + Fixed( 0.75f ));
	Fixed			h ( Fixed( -71.3f ) - Fixed( 2.29f ));
	Fixed const		h_cpy ( Fixed( 71.3f ) - Fixed( -2.29f ));
	Fixed			i ( Fixed( 60.08f ) / Fixed( -3.09f ));
	Fixed			test(10.2f);
	f = Fixed ( 1234.4321f );

	info_values(a, b, c, d, e, f, g, h, i, test);
	std::cout << YELLOW << "-----------------COMPARISON-----------------" << RESET << std::endl;
	std::cout << std::boolalpha <<"d > e: " << CYAN << (d > e) << RESET << std::endl;
	std::cout << std::boolalpha <<"a < b: " << CYAN << (a < b) << RESET << std::endl;
	std::cout << std::boolalpha <<"b >= f: " << CYAN << (b >= f) << RESET << std::endl;
	std::cout << std::boolalpha <<"c >= e: " << CYAN << (c <= e) << RESET << std::endl;
	std::cout << std::boolalpha <<"a == b: " << CYAN << (a == b) << RESET << std::endl;
	std::cout << std::boolalpha <<"c != e: " << CYAN << (c != e) << RESET << std::endl;
	std::cout << YELLOW << "--------------END-COMPARISON----------------" << RESET << std::endl;
	std::cout << YELLOW << "-----------------ARITHMETIC-----------------" << RESET << std::endl;
	std::cout << "b is the result of (5.05f * 2): " << CYAN << b << RESET <<  std::endl;
	std::cout << "g is the result of (234.45f + 0.75f): " << CYAN << g << RESET <<  std::endl;
	std::cout << "h is the result of (71.3f - 2.29f): " << CYAN << h << RESET <<  std::endl;
	std::cout << "i is the result of (60 / 3): " << CYAN << i << RESET <<  std::endl;
	std::cout << YELLOW << "--------------END-ARITHMETIC----------------" << RESET << std::endl;
	std::cout << YELLOW << "-------------INCREMENT/DECREMENT------------" << RESET << std::endl;
	std::cout << "a: " << CYAN << a << RESET << std::endl;
	std::cout << "++a: " << CYAN << ++a << RESET << std::endl;
    std::cout << "a: " << CYAN << a << RESET << std::endl;
	std::cout << "a++: " << CYAN << a++ << RESET << std::endl;
	std::cout << "a: " << CYAN << a << RESET << std::endl;
	std::cout << "--a: " << CYAN << --a << RESET << std::endl;
	std::cout << "a: " << CYAN << a << RESET << std::endl;
	std::cout << "a--: " << CYAN << a-- << RESET << std::endl;
	std::cout << "a: " << CYAN << a << RESET << std::endl;
	std::cout << YELLOW << "----------END-INCREMENT/DECREMENT-----------" << RESET << std::endl;
	std::cout << YELLOW << "-------------------MIN/MAX------------------" << RESET << std::endl;
	std::cout << "max(a,b): " << CYAN << Fixed::max( a, b ) << RESET << std::endl;
	std::cout << "max const(d,h): " << CYAN << Fixed::max( d_cpy, h_cpy ) << RESET << std::endl;
	std::cout << "min(h,g): " << CYAN << Fixed::min( h, g ) << RESET << std::endl;
	std::cout << "min const(d,h): " << CYAN << Fixed::min( d_cpy, h_cpy ) << RESET << std::endl;
	std::cout << YELLOW << "----------------END-MIN/MAX------------------" << RESET << std::endl;
}

/* int main( void ) 
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    //Fixed c = ++a;

    //std::cout << "c1: " << c << std::endl;
    //certo
    std::cout << "1: " << a << std::endl;
    std::cout << "2: " <<++a << std::endl;
    std::cout << "3: " << a << std::endl;
    std::cout << "4: " << a++ << std::endl;
    std::cout << "5: " << a << std::endl;
    //errado
    std::cout << "6: " << b << std::endl;
    std::cout << "7: " << Fixed::max( a, b ) << std::endl;
    //std::cout << "c2: " << c << std::endl;
    return 0;
} */
