/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:26:40 by rimarque          #+#    #+#             */
/*   Updated: 2024/04/05 20:25:15 by rimarque         ###   ########.fr       */
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
    std::cout << "Name constructor called: " 
    << name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap desconstructor called" << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap's name: " << _name << std::endl
    << "ClapTrap's name: " << ClapTrap::_name << std::endl
    << "FragTrap's hit points: " << _hitPoints<< std::endl
    << "ScavTrap's energy points: " << _energyPoints << std::endl;
}