/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:53:50 by rita              #+#    #+#             */
/*   Updated: 2024/04/08 15:24:51 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/FragTrap.hpp"

//Default constructor
FragTrap::FragTrap(): ClapTrap(100, 100, 30)
{
    std::cout << "FragTrap default constructor called" << std::endl;
}

//Name constructor
FragTrap::FragTrap(std::string name): ClapTrap(name)
{
    _hitPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap name constructor called: "
    << name << " was created!" << std::endl;
}

//Copy constructor
FragTrap::FragTrap(const FragTrap &copy): ClapTrap(copy)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
}
//Copy asigment operator overload -> nao é necessário
FragTrap& FragTrap::operator= (const FragTrap& copy)
{
    if(this == &copy)
        return *this;
    _name = copy._name;
    _hitPoints = copy._hitPoints;
    _energyPoints = copy._energyPoints;
    _attackDamage = copy._attackDamage;
    std::cout << "FragTrap copy assignment operator overload" << std::endl;
    return (*this);
}

void    FragTrap::highFivesGuys()
{
    std::cout << "Hello, my name is " << GREEN << _name << RESET
    << "! I'm from the FragTrap tribe! Can I get a high five?" << std::endl; 
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called" << _name 
    << " is dead" << std::endl;
}