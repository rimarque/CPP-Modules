/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 23:51:02 by rita              #+#    #+#             */
/*   Updated: 2024/03/14 15:31:50 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ScavTrap.hpp"

//Ver se os construtores, o copy assigment operator overload e o guardGate funcionam
/* int main()
{
    ClapTrap    clapDefault;
    ClapTrap    skyBison("Appa");
    ClapTrap    copy_skyBison(skyBison);
    ScavTrap    scavDefault;
    ScavTrap    firebender("Zuko");
    ScavTrap    copy_firebender(firebender);
    
    skyBison.setAttackDamage(8);
    firebender.setAttackDamage(5);
    copy_skyBison = skyBison;
    copy_firebender = firebender;
    std::cout << WHITE << "\nCLAPTRAP: " << std::endl;
    std::cout <<  CYAN << "\nDISPLAY CLAP DEFAULT" << RESET << std::endl;
    clapDefault.display();
    std::cout << CYAN << "\nDISPLAY SKY BISON: " << RESET << std::endl;
    skyBison.display();
    std::cout << CYAN << "\nDISPLAY COPY SKY BISON: " << RESET << std::endl;
    copy_skyBison.display();
    std::cout << std::endl;
    std::cout << WHITE << "\nSCAVTRAP: " << std::endl;
    std::cout << PURPLE << "\nDISPLAY LAST SCAV DEFAULT: " << RESET << std::endl;
    scavDefault.display();
    std::cout <<  PURPLE << "\nDISPLAY FIREBENDER" << RESET << std::endl;
    firebender.display();
    std::cout <<  PURPLE << "\nDISPLAY COPY FIREBENDER" << RESET << std::endl;
    copy_firebender.display();
    std::cout << std::endl;
    firebender.guardGate();
    std::cout << std::endl;
    return 0;
} */

//Testar ScavTrap
int main()
{
    ScavTrap    skyBison("Appa");
    ScavTrap    avatar("Ang");
    ClapTrap    firebender("Zuko", 50, 10, 10);
    int         i = 1;

    std::cout << CYAN << "\nDISPLAY SKY BISON: " << RESET << std::endl;
    skyBison.display();
    std::cout << std::endl; 
    skyBison.guardGate();
    std::cout << ORANGE << "\nDISPLAY AVATAR: " << RESET << std::endl;
    avatar.display();
    std::cout <<  PURPLE << "\nDISPLAY FIREBENDER" << RESET << std::endl;
    firebender.display();
    std::cout << std::endl;
    while(firebender.checkPoints(" IS DEAD: ") && avatar.checkPoints(" IS DEAD: "))
    {
        std::cout << CYAN <<"ROUND " << i++ << RESET << " \n";
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