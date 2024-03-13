/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 22:13:51 by rita              #+#    #+#             */
/*   Updated: 2024/03/12 23:54:56 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CPLAPTRAP_H

# include <iostream>
# include <string.h>
# include <cctype>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <iomanip> 
# include <cstdlib>
# include <ctime>
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
        ClapTrap& operator= (const ClapTrap& copy);
        void display();
        ~ClapTrap();
        
};

#endif