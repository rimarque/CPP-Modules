/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 23:51:02 by rita              #+#    #+#             */
/*   Updated: 2024/04/08 12:24:41 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ClapTrap.hpp"

int main()
{
    ClapTrap    skyBison("Appa");
    ClapTrap    firebender("Zuko");
    
    skyBison.setAttackDamage(8);
    std::cout << CYAN << "\nDISPLAY SKY BISON: " << RESET << std::endl;
    skyBison.display();
    std::cout <<  PURPLE << "\nDISPLAY FIREBENDER" << RESET << std::endl;
    firebender.display();
    std::cout << std::endl;
    while(firebender.checkPoints(" IS DEAD ") && skyBison.checkPoints(" IS DEAD "))
    {
        skyBison.attack("Zuko");
        if(skyBison.checkPoints(""))
            firebender.takeDamage(skyBison.getAttackDamage());
        firebender.beRepaired(1);
        firebender.attack("Appa");
        if(firebender.checkPoints(""))
            skyBison.takeDamage(firebender.getAttackDamage());
        skyBison.beRepaired(5);
        std::cout << CYAN << "\nDISPLAY SKY BISON: " << RESET << std::endl;
        skyBison.display();
        std::cout << PURPLE << "\nDISPLAY FIREBENDER: " << RESET << std::endl;
        firebender.display();
        std::cout << std::endl; 
    }
    return 0;
}