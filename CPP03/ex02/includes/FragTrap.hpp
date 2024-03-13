/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:57:35 by rita              #+#    #+#             */
/*   Updated: 2024/03/13 19:21:40 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include "ClapTrap.hpp"
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
    void        highFivesGuys();
    //Destructor
    ~FragTrap();
};

#endif