/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:26:40 by rimarque          #+#    #+#             */
/*   Updated: 2024/04/06 14:54:41 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
    std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
    :ClapTrap(name), FragTrap(name), ScavTrap(name)
{
    _name = name;
    std::cout << "Diamond Trap name constructor called: " 
    << name << std::endl;
}
void    DiamondTrap::attack(const std::string& target)
{
    this->ScavTrap::attack(target);
}
void DiamondTrap::whoAmI()
{
    std::cout << CYAN <<  "\nI amd Diamond Trap!\n" << RESET
    << "My name is " << _name << std::endl
    << "ClapTrap's name is " << ClapTrap::_name << std::endl;
}

void DiamondTrap::display()
{
    std::cout << CYAN << "\nDISPLAY:" << RESET << std::endl
    << "name: " << _name << std::endl
    << "hit points: " << _hitPoints << std::endl
    << "energy points: " << _energyPoints << std::endl
    << "attack damage: " << _attackDamage << std::endl << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap desconstructor called" << std::endl;
}