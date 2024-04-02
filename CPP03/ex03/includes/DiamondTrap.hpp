/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:54:35 by rimarque          #+#    #+#             */
/*   Updated: 2024/04/02 18:33:56 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMINDTRAP_H
# define DIAMONDTRAP_H

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
//Duvida se é necessário fazer a ortodoxol cannonical form: copy assigment operator overload?
class DiamondTrap: public ClapTrap
{
  public:
    //Default Constuctor
    DiamondTrap();
    //Name constructor
    DiamondTrap(std::string name);
    //Copy constructor
    DiamondTrap(const DiamondTrap &copy);
    //copy assigment operator overload -> funciona na mesma sem isto
    DiamondTrap&   operator= (const DiamondTrap& copy);
    void        attack(const std::string& target);
    void        highFivesGuys();
    //Destructor
    ~DiamondTrap();
};

#endif