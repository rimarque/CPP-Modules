/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 23:51:02 by rita              #+#    #+#             */
/*   Updated: 2024/04/08 19:16:44 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/DiamondTrap.hpp"


/* int main()
{
    DiamondTrap a("rita");
    DiamondTrap b("monica");
    ScavTrap    c("gaspar");
    ClapTrap    d("test");

    std::cout << std::endl;
    a.guardGate();
    std::cout << std::endl;
    b.highFivesGuys();
    a.whoAmI();
    b.whoAmI();
    std::cout << std::endl;
    a.duel(b);
    c.duel(d);
    return 0;
} */

int main()
{
    ScavTrap    c("gaspar");
    ClapTrap    d("test");

    std::cout << std::endl;
    c.duel(d);
    return 0;
}