/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:57:35 by rita              #+#    #+#             */
/*   Updated: 2024/03/14 16:22:36 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include "ClapTrap.hpp"
//Duvida se é necessário fazer a ortodoxol cannonical form: copy assigment operator overload?
class ScavTrap: public ClapTrap
{
  public:
    //Default Constuctor
    ScavTrap();
    //Name constructor
    ScavTrap(std::string name);
    //Copy constructor
    ScavTrap(const ScavTrap &copy);
    //copy assigment operator overload -> funciona na mesma sem isto
    ScavTrap&   operator= (const ScavTrap& copy);
    void        attack(const std::string& target);
    void        guardGate();
    //Destructor
    ~ScavTrap();
};

#endif