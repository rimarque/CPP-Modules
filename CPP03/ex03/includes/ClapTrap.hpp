/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 22:13:51 by rita              #+#    #+#             */
/*   Updated: 2024/04/08 19:43:46 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

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
# define ORANGE "\033[1;38;2;255;165;0m"
# define RESET "\033[0m"

class ClapTrap 
{
    protected:
        std::string _name;
        int         _hitPoints;
        int         _energyPoints;
        int         _attackDamage;
    public:
        //Default constructor
        ClapTrap();
        //Constructor that inicialized _name
        ClapTrap(std::string name);
        //Constructor that inicializes int atributes
        ClapTrap(int hitPoints, int energyPoints, int attackDamage);
        //Constructor that inicializes all atributes
        ClapTrap(std::string name, int hitPoints, int energyPoints, int attackDamage);
        //Copy constructor
        ClapTrap(const ClapTrap& copy);
        //Copy assignment constructor
        ClapTrap&   operator= (const ClapTrap& copy);
        //Myfuncions
        std::string         getName();
        int                 getAttackDamage();
        void                setAttackDamage(int a);
        virtual void        attack(const std::string& target);
        void                takeDamage(unsigned int amount);
        void                beRepaired(unsigned int amount);
        bool                checkPoints(std::string msg);
        virtual void        display();
        void                duel(ClapTrap fighter);
        ~ClapTrap();
        
};

#endif