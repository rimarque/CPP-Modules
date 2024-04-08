/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:57:35 by rita              #+#    #+#             */
/*   Updated: 2024/04/08 15:24:41 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include "ScavTrap.hpp"
class FragTrap: public ClapTrap
{
  public:
    //Default Constuctor
    FragTrap();
    //Name constructor
    FragTrap(std::string name);
    //Copy constructor
    FragTrap(const FragTrap &copy);
    //copy assigment operator overload
    FragTrap&   operator= (const FragTrap& copy);
    void        highFivesGuys();
    //Destructor
    ~FragTrap();
};

#endif