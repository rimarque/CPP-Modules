/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:53:50 by rita              #+#    #+#             */
/*   Updated: 2024/04/05 20:18:44 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ScavTrap.hpp"

//Default constructor
ScavTrap::ScavTrap(): ClapTrap(100, 50, 20)
{
    std::cout << "ScavTrap default constructor called" << std::endl;
}

//Name constructor
ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
    _energyPoints = 50;
    std::cout << "ScavTrap name constructor called: "
    << name << std::endl;
}

//Copy constructor
ScavTrap::ScavTrap(const ScavTrap &copy): ClapTrap(copy)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
}
//Copy asigment operator overload -> nao é necessário
ScavTrap& ScavTrap::operator= (const ScavTrap& copy)
{
    if(this == &copy)
        return *this;
    _name = copy._name;
    _hitPoints = copy._hitPoints;
    _energyPoints = copy._energyPoints;
    _attackDamage = copy._attackDamage;
    std::cout << "ScavTrap copy assignment operator overload" << std::endl;
    return (*this);
}

void ScavTrap::attack(const std::string& target)
{
    if(!this->checkPoints(" IS UNABLE TO ATTACK: "))
        return ;
    if(_attackDamage == 1)
        std::cout << "ScavTrap " << ORANGE << _name << RESET << " attacks " << target
        << " causing " << _attackDamage << " point of damage!" << std::endl;
    else
        std::cout << "ScavTrap " << ORANGE << _name << RESET << " attacks " << target
        << " causing " << _attackDamage << " points of damage!" << std::endl;
    _energyPoints--;
    if(_energyPoints < 0)
        _energyPoints = 0;
}

void    ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << ORANGE << _name << RESET
    << " is now in Gate Keeper mode" << std::endl; 
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
}