/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 22:13:51 by rita              #+#    #+#             */
/*   Updated: 2024/04/06 15:19:20 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CPLAPTRAP_H

# include <iostream>
# include <string.h>
# include <unistd.h>
# include <math.h>
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define PURPLE "\033[1;35m"
# define YELLOW "\033[1;33m"
# define WHITE 	"\033[1;37m"
# define CYAN "\033[1;36m"
# define RESET "\033[0m"

class ClapTrap 
{
    private:
        std::string _name;
        int         _hitPoints;
        int         _energyPoints;
        int         _attackDamage;
    public:
        //Default constructor
        ClapTrap();
        //Constructor that inicialized _name
        ClapTrap(std::string name);
        //Copy constructor
        ClapTrap(const ClapTrap& copy);
        //Copy assignment constructor
        ClapTrap&   operator= (const ClapTrap& copy);
        a = b;
        //Myfuncions
        int         getAttackDamage();
        void        setAttackDamage(int a);
        void        attack(const std::string& target);
        void        takeDamage(unsigned int amount);
        void        beRepaired(unsigned int amount);
        bool        checkPoints(std::string msg);
        void        display();
        ~ClapTrap();
        
};

claptrap a;
claptrap b;

a = b;
claptrap c = a + b;
#endif