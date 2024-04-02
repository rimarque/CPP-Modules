/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:57:35 by rita              #+#    #+#             */
/*   Updated: 2024/03/14 16:22:21 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include "ScavTrap.hpp"
//Duvida se é necessário fazer a ortodoxol cannonical form: copy assigment operator overload?
class FragTrap: public ClapTrap
{
  public:
    //Default Constuctor
    FragTrap();
    //Name constructor
    FragTrap(std::string name);
    //Copy constructor
    FragTrap(const FragTrap &copy);
    //copy assigment operator overload -> funciona na mesma sem isto
    FragTrap&   operator= (const FragTrap& copy);
    void        attack(const std::string& target);
    void        highFivesGuys();
    //Destructor
    ~FragTrap();
};

#endif