/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:59:05 by rita              #+#    #+#             */
/*   Updated: 2024/03/08 14:56:55 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Fixed.hpp"

//*1 << _fractionalBits == (2^_fractionalBits) == 256,
//*se _fractionalBits = 8;

Fixed::Fixed(){
    _fixedPointValue = 0;
    std::cout << "Default Fixed constructor called" << std::endl;
    return ;
}

//Copy constructor
Fixed::Fixed(const Fixed& copy){ //const reference
    _fixedPointValue = copy._fixedPointValue;
    std::cout << "Copy Fixed constructor called" << std::endl;
    return ;
}

//Copy assignment constructor
Fixed& Fixed::operator= (const Fixed& copy)
{
    // self-assignment check
    if(this == &copy)
        return *this;
    this->_fixedPointValue = copy._fixedPointValue;
    std::cout << "Fixed Copy assignment operator overload" << std::endl;
    return (*this);
}

//int -> fixed.point 
//shiftar 8 bits para a esquerda (<< 8) ou * 256
Fixed::Fixed(const int number)
{
    // Usando um tipo de dados de maior precisão para cálculos intermediários
    long long x = static_cast<long long>(number) << _fractionalBits; 

    // Convertendo o resultado de volta para o tipo de dados fixo
    this->_fixedPointValue = static_cast<int>(x);

    std::cout << "Int constructor called" << std::endl;
}

//float -> fixed.point
//shiftar 8 bits para a esquerda * (1 << _fractionalBits) ou * 256
//roundf -> devolve-te o numero inteiro mais próximo
Fixed::Fixed(const float number)
{
    // Converta o número de ponto flutuante para ponto fixo com precisão adequada
    // Preserva a precisão usando roundf para arredondar corretamente o número
    this->_fixedPointValue = static_cast<int>(roundf(number * 256.0f));

    std::cout << "Float constructor called" << std::endl;
}

//returns the raw value of the fixed-point value
int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return(this->_fixedPointValue);
}

//sets the raw value of the fixed-point number.
void Fixed::setRawBits( int const raw)
{
    this->_fixedPointValue = raw;
    std::cout << "setRawBits member function called" << std::endl;
}

//fixed_point -> float
// / (1 << _fractionalBits) ou / 256
float   Fixed::toFloat(void) const
{
    return((float)this->_fixedPointValue / 256);
}

//fixed_point -> int
// / (1 << _fractionalBits) ou / 256
int   Fixed::toInt(void) const
{
    return((int)this->_fixedPointValue / 256);
}

//Comparison operators
bool    Fixed::operator> (const Fixed& compare) const
{
    std::cout << "Comparison operator overload '>' called" << std::endl;
    return(this->_fixedPointValue > compare._fixedPointValue);
}

bool    Fixed::operator< (const Fixed& compare) const
{
    std::cout << "Comparison operator overload'<' called" << std::endl;
    return(this->_fixedPointValue < compare._fixedPointValue); 
}

bool    Fixed::operator>= (const Fixed& compare) const
{
    std::cout << "Comparison operator overload'>=' called" << std::endl;
    return(this->_fixedPointValue >= compare._fixedPointValue); 
}

bool    Fixed::operator<= (const Fixed& compare) const
{
    std::cout << "Comparison operator overload'<=' called" << std::endl;
    return(this->_fixedPointValue <= compare._fixedPointValue);
}

bool    Fixed::operator== (const Fixed& compare) const
{
    std::cout << "Comparison operator overload'==' called" << std::endl;
    return(this->_fixedPointValue == compare._fixedPointValue);
}

bool    Fixed::operator!= (const Fixed& compare) const
{
    std::cout << "Comparison operator overload'!=' called" << std::endl;
    return(this->_fixedPointValue <= compare._fixedPointValue);
}

//Aritmetic operators

Fixed Fixed::operator+ (const Fixed& copy) const
{
    Fixed result;
    std::cout << "Arithmetic '+' operator overload called" << std::endl;

    // Realiza a adição mantendo mais bits durante o cálculo
    long long sum = static_cast<long long>(_fixedPointValue) + static_cast<long long>(copy._fixedPointValue);

    // Ajusta o resultado para o número correto de bits fracionários
    result._fixedPointValue = static_cast<int>(sum);

    return result;
}

Fixed Fixed::operator- (const Fixed& copy) const
{
    Fixed result;
    std::cout << "Arithmetic '-' operator overload called" << std::endl;

    // Realiza a subtração mantendo mais bits durante o cálculo
    long long difference = static_cast<long long>(_fixedPointValue) - static_cast<long long>(copy._fixedPointValue);

    // Ajusta o resultado para o número correto de bits fracionários
    result._fixedPointValue = static_cast<int>(difference);

    return result;
}

// / (1 << _fractionalBits) ou / 256
Fixed Fixed::operator* (const Fixed& copy) const
{
    Fixed result;
    
    std::cout << "Aritmetic '*' operator overload called" << std::endl;
    //Perform multiplication using a larger integer type to prevent overflow
    long long product = static_cast<long long>(_fixedPointValue) * static_cast<long long>(copy._fixedPointValue);
    result._fixedPointValue = static_cast<int>(product / 256);
    return result;
}

//(_fixedPointValue << _fractionalBits) ou * (1 << _fractionalBits) ou * 256
Fixed Fixed::operator/ (const Fixed& copy) const
{
    Fixed result;
    
    std::cout << "Aritmetic '/' operator overload called" << std::endl;
    long long dividend = static_cast<long long>(_fixedPointValue) * 256;
    long long divisor = static_cast<long long>(copy._fixedPointValue);
    if(divisor == 0)
    {
        std::cout << "error: division by zero" << std::endl;
        return(result);
    }
    result._fixedPointValue = static_cast<int>(dividend / divisor);
    return result;
}

//Increment/decrement operators
Fixed    Fixed::operator++ () //++i
{
    std::cout << "'Pre Increment' operator overload called" << std::endl;
    ++_fixedPointValue;
    return (*this);
}

Fixed    Fixed::operator-- () //--i
{
    std::cout << "'Pre decrement' operator overload called" << std::endl;
    --_fixedPointValue;
    return (*this);
}

Fixed    Fixed::operator++ (int) //i++
{
    Fixed   copy;
    std::cout << "'Pos Increment' operator overload called" << std::endl;
    copy._fixedPointValue = _fixedPointValue++;
    return (copy);
}

Fixed    Fixed::operator-- (int) //i--
{
    Fixed   copy;

    std::cout << "'Pro decrement' operator overload called" << std::endl;
    copy._fixedPointValue = _fixedPointValue--;
    return (copy);     
}

//Add these four public overloaded member functions to your class:
Fixed&  Fixed::min(Fixed& a, Fixed& b) //retorna o mais pequeno
{   
    std::cout << "min function called" << std::endl;
    if(a.getRawBits() < b.getRawBits())
        return(a);
    return(b);
}

//basta um dos parametros ser const para set esta a funçao chamada
const Fixed&    Fixed::min(const Fixed& a, const Fixed& b) //retorna referencia ao mais pequeno
{
    std::cout << "const min function called" << std::endl;
    if(a.getRawBits() < b.getRawBits())
        return(a);
    return(b);
}
Fixed&  Fixed::max(Fixed& a, Fixed& b) //retorna o maior
{
    std::cout << "max function called" << std::endl;
    if(a.getRawBits() > b.getRawBits())
        return(a);
    return(b);
}

const Fixed&  Fixed::max(const Fixed& a, const Fixed& b) //retorna referencia ao maior
{
    std::cout << "const max function called" << std::endl;
    if(a.getRawBits() > b.getRawBits())
        return(a);
    return(b);
}

Fixed::~Fixed(){
    std::cout << "Fixed Destructor caled" << std::endl;
    return ;
}