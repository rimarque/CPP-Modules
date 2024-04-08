/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:57:35 by rita              #+#    #+#             */
/*   Updated: 2024/04/08 12:26:51 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include "ClapTrap.hpp"
class ScavTrap: public ClapTrap
{
  public:
    //Default Constuctor
    ScavTrap();
    //Name constructor
    ScavTrap(std::string name);
    //Copy constructor
    ScavTrap(const ScavTrap &copy);
    //copy assigment operator overload
    ScavTrap&   operator= (const ScavTrap& copy);
    void        attack(const std::string& target);
    void        guardGate();
    //Destructor
    ~ScavTrap();
};

#endif