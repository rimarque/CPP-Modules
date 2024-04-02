/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 23:51:02 by rita              #+#    #+#             */
/*   Updated: 2024/03/14 17:14:26 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/FragTrap.hpp"

/* void    clapFragDuel(ClapTrap clapFighter, FragTrap fragFighter)
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
        fragFighter.attack("Ang");
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

void    clapScavDuel(ClapTrap clapFighter, ScavTrap scavFighter)
{
    int i = 1;

    std::cout << CYAN << "\n        CLAP SCAV DUEL " << RESET << std::endl;
    while(clapFighter.checkPoints(" IS DEAD: ") && scavFighter.checkPoints(" IS DEAD: "))
    {
        std::cout << CYAN <<"ROUND " << i++ << RESET << " \n";
        scavFighter.attack("Zuko");
        if(scavFighter.checkPoints(""))
            clapFighter.takeDamage(scavFighter.getAttackDamage());
        clapFighter.beRepaired(5);
        clapFighter.attack("Appa");
        if(clapFighter.checkPoints(""))
            scavFighter.takeDamage(clapFighter.getAttackDamage());
        scavFighter.beRepaired(5);
        std::cout << ORANGE << "\nDISPLAY SCAVTRAP: " << RESET << std::endl;
        scavFighter.display();
        std::cout << PURPLE << "\nDISPLAY CLAPTRAP: " << RESET << std::endl;
        clapFighter.display();
        std::cout << std::endl; 
    }
    std::cout << std::endl;
    
}

//Test with separate funtion per duel
int main()
{
    ScavTrap    skyBison("Appa");
    ClapTrap    firebender("Zuko");
    ScavTrap    avatar("Ang");
    FragTrap    earthbender("Bumi");

    std::cout << ORANGE << "\nDISPLAY SKY BISON: " << RESET << std::endl;
    skyBison.display();
    std::cout << std::endl; 
    skyBison.guardGate();
    std::cout << ORANGE << "\nDISPLAY AVATAR: " << RESET << std::endl;
    avatar.display();
    std::cout <<  PURPLE << "\nDISPLAY FIREBENDER" << RESET << std::endl;
    firebender.display();
    std::cout << std::endl;
    clapScavDuel(firebender, avatar);
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
} */

//Test wih claptrap member function duel
int main()
{
    ScavTrap    skyBison("Appa");
    ClapTrap    firebender("Zuko");
    ScavTrap    avatar("Ang");
    FragTrap    earthbender("Bumi");

    std::cout << ORANGE << "\nDISPLAY SKY BISON: " << RESET << std::endl;
    skyBison.display();
    std::cout << std::endl; 
    skyBison.guardGate();
    std::cout << std::endl; 
    avatar.duel(firebender);
    std::cout << std::endl;
    earthbender.duel(firebender);
    std::cout << std::endl;
    earthbender.duel(avatar);
    std::cout << std::endl; 
    return 0;
}