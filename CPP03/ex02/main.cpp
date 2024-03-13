/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 23:51:02 by rita              #+#    #+#             */
/*   Updated: 2024/03/13 19:21:13 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/FragTrap.hpp"

//Testar FragTrap
int main()
{
    FragTrap    skyBison("Appa");
    FragTrap    avatar("Ang");
    FragTrap    firebender("Zuko");
    int         i = 1;

    std::cout << CYAN << "\nDISPLAY SKY BISON: " << RESET << std::endl;
    skyBison.display();
    std::cout << std::endl; 
    skyBison.highFivesGuys();
    std::cout << ORANGE << "\nDISPLAY AVATAR: " << RESET << std::endl;
    avatar.display();
    std::cout <<  PURPLE << "\nDISPLAY FIREBENDER" << RESET << std::endl;
    firebender.display();
    std::cout << std::endl;
    while(firebender.checkPoints(" IS DEAD: ") && avatar.checkPoints(" IS DEAD: "))
    {
        std::cout << WHITE <<"ROUND " << i++ << " \n";
        avatar.attack("Zuko");
        if(avatar.checkPoints(""))
            firebender.takeDamage(avatar.getAttackDamage());
        firebender.beRepaired(5);
        firebender.attack("Appa");
        if(firebender.checkPoints(""))
            avatar.takeDamage(firebender.getAttackDamage());
        avatar.beRepaired(5);
        std::cout << ORANGE << "\nDISPLAY AVATAR: " << RESET << std::endl;
        avatar.display();
        std::cout << PURPLE << "\nDISPLAY FIREBENDER: " << RESET << std::endl;
        firebender.display();
        std::cout << std::endl; 
    }
    std::cout << std::endl;
    return 0;
}