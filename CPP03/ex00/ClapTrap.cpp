/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 22:38:12 by rita              #+#    #+#             */
/*   Updated: 2024/03/13 00:06:35 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ClapTrap.hpp"

ClapTrap::ClapTrap()
    :   _hitPoints(10),
        _energyPoints(10),
        _attackDamage(0)
{
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
    :   _name(name),
        _hitPoints(10),
        _energyPoints(10),
        _attackDamage(0)
{
    std::cout << "Name constructor called" << std::endl;
}

//Copy constructor
ClapTrap::ClapTrap(const ClapTrap& copy)
    :   _name(copy._name),
        _hitPoints(copy._hitPoints),
        _energyPoints(copy._energyPoints),
        _attackDamage(copy._attackDamage)
{
    std::cout << "Copy constructor called" << std::endl;
    return ;
}

//Copy asigment operator overload
ClapTrap& ClapTrap::operator= (const ClapTrap& copy)
{
    if(this == &copy)
        return *this;
    _name = copy._name;
    _hitPoints = copy._hitPoints;
    _energyPoints = copy._energyPoints;
    _attackDamage = copy._attackDamage;
    std::cout << "Copy assignment operator overload" << std::endl;
    return (*this);
}

void ClapTrap::display()
{
    std::cout << "name: " << _name << std::endl
    << "hit points: " << _hitPoints << std::endl
    << "energy points: " << _energyPoints << std::endl
    << "attack damage: " << _attackDamage << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;
}