/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 23:51:02 by rita              #+#    #+#             */
/*   Updated: 2024/03/13 17:01:18 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ScavTrap.hpp"

int main()
{
    ClapTrap    avatar;
    ClapTrap    skyBison("Appa");
    ClapTrap    copy_skyBison(skyBison);
    ScavTrap    lastAirbender;
    ScavTrap    firebender("Zuko");
    ScavTrap    copy_firebender(firebender);
    
    skyBison.setAttackDamage(8);
    firebender.setAttackDamage(5);
    copy_skyBison = skyBison;
    copy_firebender = firebender;
    std::cout << WHITE << "\nCLAPTRAP: " << std::endl;
    std::cout <<  PURPLE << "\nDISPLAY AVATAR" << RESET << std::endl;
    avatar.display();
    std::cout << CYAN << "\nDISPLAY SKY BISON: " << RESET << std::endl;
    skyBison.display();
    std::cout << CYAN << "\nDISPLAY COPY SKY BISON: " << RESET << std::endl;
    copy_skyBison.display();
    std::cout << std::endl;
    std::cout << WHITE << "\nSCAVTRAP: " << std::endl;
    std::cout << CYAN << "\nDISPLAY LAST AIRBENDER: " << RESET << std::endl;
    lastAirbender.display();
    std::cout <<  PURPLE << "\nDISPLAY FIREBENDER" << RESET << std::endl;
    firebender.display();
    std::cout <<  PURPLE << "\nDISPLAY COPY FIREBENDER" << RESET << std::endl;
    copy_firebender.display();
    std::cout << std::endl;
    firebender.guardGate();
    return 0;
}