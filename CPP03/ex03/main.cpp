/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 23:51:02 by rita              #+#    #+#             */
/*   Updated: 2024/04/07 11:52:00 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/DiamondTrap.hpp"


int main()
{
    DiamondTrap a("rita");
    DiamondTrap b("monica");
    ClapTrap c("naty");
    ScavTrap d("roberto");
    FragTrap e("gaspar");

    std::cout << PURPLE << "\n\nTesting copy constructor\n" << RESET;
    DiamondTrap copy(a);
    a.whoAmI();
    a.display();
    copy.whoAmI();
    copy.display();
    std::cout << PURPLE << "\n\nTesting copy assigment operator\n" << RESET;
    b = a;
    a.whoAmI();
    a.display();
    b.whoAmI();
    b.display();
    std::cout << std::endl;
    /* a.duel(b);
    d.duel(a); */
    /* std::cout << PURPLE << "\nDIAMOND VS DIAMOND\n" << RESET;
    a.whoAmI();
    a.display();
    b.whoAmI();
    b.display();
    while(b.checkPoints(" IS DEAD ") && a.checkPoints(" IS DEAD "))
    {
        a.attack("monica");
        if(a.checkPoints(""))
            b.takeDamage(a.getAttackDamage());
        b.beRepaired(1);
        b.attack("rita");
        if(b.checkPoints(""))
            a.takeDamage(b.getAttackDamage());
        a.beRepaired(5);
        a.display();
        b.display();
        std::cout << std::endl;
    } */
    /* std::cout << PURPLE << "\nDIAMOND VS CLAP\n" << RESET;
    a.display();
    c.display();
    while(b.checkPoints(" IS DEAD ") && c.checkPoints(" IS DEAD "))
    {
        c.attack("monica");
        if(c.checkPoints(""))
            b.takeDamage(c.getAttackDamage());
        b.beRepaired(1);
        b.attack("naty");
        if(b.checkPoints(""))
            c.takeDamage(b.getAttackDamage());
        c.beRepaired(5);
        c.display();
        b.display();
        std::cout << std::endl; 
    } */
/*     std::cout << PURPLE << "\nDIAMOND VS SCAV\n" << RESET;
    a.display();
    d.display();
    while(b.checkPoints(" IS DEAD ") && d.checkPoints(" IS DEAD "))
    {
        d.attack("monica");
        if(d.checkPoints(""))
            b.takeDamage(d.getAttackDamage());
        b.beRepaired(1);
        b.attack("roberto");
        if(b.checkPoints(""))
            d.takeDamage(b.getAttackDamage());
        d.beRepaired(5);
        d.display();
        b.display();
        std::cout << std::endl; 
    } */
   /*  std::cout << PURPLE << "\nDIAMOND VS FRAG\n" << RESET;
    a.display();
    e.display();
    while(b.checkPoints(" IS DEAD ") && e.checkPoints(" IS DEAD "))
    {
        e.attack("monica");
        if(e.checkPoints(""))
            b.takeDamage(e.getAttackDamage());
        b.beRepaired(1);
        b.attack("gaspar");
        if(b.checkPoints(""))
            e.takeDamage(b.getAttackDamage());
        e.beRepaired(5);
        e.display();
        b.display();
        std::cout << std::endl; 
    }
    return 0; */
}