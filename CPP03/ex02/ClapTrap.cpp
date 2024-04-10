/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 22:38:12 by rita              #+#    #+#             */
/*   Updated: 2024/04/08 18:55:00 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ClapTrap.hpp"

ClapTrap::ClapTrap()
    :   _hitPoints(10),
        _energyPoints(10),
        _attackDamage(0)
{
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(int hitPoints, int energyPoints, int attackDamage)
    :   _hitPoints(hitPoints),
        _energyPoints(energyPoints),
        _attackDamage(attackDamage)
{
    std::cout << "ClapTrap atributtes constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
    :   _name(name),
        _hitPoints(10),
        _energyPoints(10),
        _attackDamage(0)
{
    std::cout << "ClapTrap name constructor called: " 
    << name << " was created" << std::endl;
}

ClapTrap::ClapTrap(std::string name, int hitPoints, int energyPoints, int attackDamage)
    :   _name(name),
        _hitPoints(hitPoints),
        _energyPoints(energyPoints),
        _attackDamage(attackDamage)
{
    std::cout << "ClapTrap all constructor called: " 
    << name << " was created" << std::endl;
}

//Copy constructor
ClapTrap::ClapTrap(const ClapTrap& copy)
    :   _name(copy._name),
        _hitPoints(copy._hitPoints),
        _energyPoints(copy._energyPoints),
        _attackDamage(copy._attackDamage)
{
    std::cout << "ClapTrap copy constructor called for " 
    << copy._name << std::endl;
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
    std::cout << "ClapTrap copy assignment operator overload" << std::endl;
    return (*this);
}

int     ClapTrap::getAttackDamage()
{
    return(_attackDamage);
}

std::string     ClapTrap::getName()
{
    return(_name);
}

void    ClapTrap::setAttackDamage(int a)
{
    if(a < 0)
    {
        std::cout << RED << "ERROR: " << RESET 
        << "attack damage must be equal"
        << " to or greater than zero" << std::endl;
        return ;
    }
    _attackDamage = a;
    return ;
}

bool    ClapTrap::checkPoints(std::string msg)
{
    if(_hitPoints == 0)
    {
        if(!msg.empty())
            std::cout <<_name << RED << msg << RESET
            << "no hit points left" << std::endl;
        return false;
    }
    if(_energyPoints == 0)
    {
        if(!msg.empty())
            std::cout << _name << RED << msg << RESET
            << "no energy points left" << std::endl;
        return false;
    }
    return true;
}

void ClapTrap::attack(const std::string& target)
{
    if(!this->checkPoints(" IS UNABLE TO ATTACK: "))
        return ;
    if(_attackDamage == 1)
        std::cout << "ClapTrap " << PURPLE << _name << RESET << " attacks " << target
        << " causing " << _attackDamage << " point of damage!" << std::endl;
    else
        std::cout << "ClapTrap " << PURPLE << _name << RESET << " attacks " << target
        << " causing " << _attackDamage << " points of damage!" << std::endl;
    _energyPoints--;
    if(_energyPoints < 0)
        _energyPoints = 0;
}

void        ClapTrap::duel(ClapTrap fighter)
{
    int i = 1;

    std::cout << CYAN << "\n    DUEL BETWEEN " << _name 
    << " & " << fighter.getName() << RESET << std::endl;
    while(this->checkPoints(" IS DEAD: ") && fighter.checkPoints(" IS DEAD: "))
    {
        std::cout << CYAN <<"ROUND " << i++ << RESET << " \n";
        std::cout << ORANGE << "\nDISPLAY FIGHTER: " << RESET << std::endl;
        fighter.display();
        std::cout << PURPLE << "\nDISPLAY SELF: " << RESET << std::endl;
        this->display();
        std::cout << std::endl; 
        fighter.attack(_name);
        if(fighter.checkPoints(""))
            this->takeDamage(fighter.getAttackDamage());
        this->beRepaired(5);
        this->attack(fighter.getName());
        if(this->checkPoints(""))
            fighter.takeDamage(this->getAttackDamage());
        fighter.beRepaired(5);
    }
    std::cout << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if(!this->checkPoints(" HAS NO DAMAGE LEFT TO DO: "))
        return ;
    if(amount == 1)
        std::cout << "ClapTrap " << _name << " takes " << 
        amount << " point of damage!" << std::endl;
    else
        std::cout << "ClapTrap " << _name << " takes " << 
        amount << " points of damage!" << std::endl;
    _hitPoints -= amount;
    if(_hitPoints < 0)
        _hitPoints = 0;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if(!this->checkPoints(" IS UNABLE TO BE REPAIRED: "))
        return ;
    if(amount == 1)
        std::cout << "ClapTrap " << _name << " is repared, gaining " 
        << amount << " hit point" << std::endl;
    else
        std::cout << "ClapTrap " << _name << " is repared, gaining " 
        << amount << " hit points" << std::endl;
    _hitPoints += amount;
    _energyPoints--;
    if(_energyPoints < 0)
        _energyPoints = 0;
    return ;
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
    std::cout << "Destructor called! " << _name << " is dead" << std::endl;
}