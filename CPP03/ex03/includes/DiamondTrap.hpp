/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:54:35 by rimarque          #+#    #+#             */
/*   Updated: 2024/04/05 20:22:14 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

//*Como a FragTrap e a ScavTrap herdam da virtual claptrap, 
//*a Diomond herda diretamente da claptrap 
class DiamondTrap: public FragTrap, public ScavTrap
{
  private:
    std::string _name;
  public:
    //Default Constuctor
    DiamondTrap();
    //Name constructor
    DiamondTrap(std::string name);
    //Copy constructor
    DiamondTrap(const DiamondTrap &copy);
    //copy assigment operator overload -> funciona na mesma sem isto
    DiamondTrap&  operator= (const DiamondTrap& copy);
    void          attack(const std::string& target);
    void          whoAmI();
    //Destructor */
    ~DiamondTrap();
};

#endif