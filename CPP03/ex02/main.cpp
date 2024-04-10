/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 23:51:02 by rita              #+#    #+#             */
/*   Updated: 2024/04/08 20:25:57 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/FragTrap.hpp"

void    clapFragDuel(ClapTrap clapFighter, FragTrap fragFighter)
{
    int i = 1;

    std::cout << CYAN << "\n        CLAP FRAG DUEL " << RESET << std::endl;
    while(fragFighter.checkPoints(" IS DEAD: ") && clapFighter.checkPoints(" IS DEAD: "))
    {
        std::cout << CYAN <<"ROUND " << i++ << RESET << " \n";
        clapFighter.attack("Bumi");
        if(clapFighter.checkPoints(""))
            fragFighter.takeDamage(clapFighter.getAttackDamage());
        fragFighter.beRepaired(5);
        fragFighter.attack("Zuko");
        if(fragFighter.checkPoints(""))
            clapFighter.takeDamage(fragFighter.getAttackDamage());
        clapFighter.beRepaired(5);
        std::cout << PURPLE << "\nDISPLAY CLAPTRAP: " << RESET << std::endl;
        clapFighter.display();
        std::cout << GREEN << "\nDISPLAY FRAGTRAP: " << RESET << std::endl;
        fragFighter.display();
        std::cout << std::endl; 
    }
    std::cout << std::endl;
    
}

void    scavFragDuel(ScavTrap scavFighter, FragTrap fragFighter)
{
    int i = 1;

    std::cout << CYAN << "\n        SCAV FRAG DUEL " << RESET << std::endl;
    while(fragFighter.checkPoints(" IS DEAD: ") && scavFighter.checkPoints(" IS DEAD: "))
    {
        std::cout << CYAN <<"ROUND " << i++ << RESET << " \n";
        scavFighter.attack("Bumi");
        if(scavFighter.checkPoints(""))
            fragFighter.takeDamage(scavFighter.getAttackDamage());
        fragFighter.beRepaired(5);
        fragFighter.attack("Aang");
        if(fragFighter.checkPoints(""))
            scavFighter.takeDamage(fragFighter.getAttackDamage());
        scavFighter.beRepaired(5);
        std::cout << ORANGE << "\nDISPLAY SCAVTRAP: " << RESET << std::endl;
        scavFighter.display();
        std::cout << GREEN << "\nDISPLAY FRAGTRAP: " << RESET << std::endl;
        fragFighter.display();
        std::cout << std::endl; 
    }
    std::cout << std::endl;
    
}

int main()
{
    ClapTrap    firebender("Zuko");
    ScavTrap    avatar("Aang");
    FragTrap    earthbender("Bumi");

    std::cout << std::endl;
    std::cout << GREEN << "\nDISPLAY EARTHBENDER: " << RESET << std::endl;
    earthbender.display();
    std::cout << std::endl; 
    earthbender.highFivesGuys();
    std::cout << ORANGE << "\nDISPLAY AVATAR: " << RESET << std::endl;
    avatar.display();
    std::cout << std::endl;
    scavFragDuel(avatar, earthbender);
    std::cout << std::endl;
    std::cout <<  PURPLE << "\nDISPLAY FIREBENDER" << RESET << std::endl;
    firebender.display();
    std::cout << GREEN << "\nDISPLAY EARTHBENDER: " << RESET << std::endl;
    earthbender.display();
    std::cout << std::endl; 
    earthbender.highFivesGuys();
    std::cout << std::endl;
    clapFragDuel(firebender, earthbender);
    std::cout << std::endl;
    return 0;
}
