/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 18:09:24 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/08/29 12:58:10 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main() {
	ClapTrap a("John");
	ClapTrap b("Jane doe");

	std::cout << std::endl;

	ScavTrap s("Scav");
	FragTrap f("teste");
	FragTrap f2("Frag");

	f = f2;

	s.attack("Jane doe");
	f.attack("Jane doe");
	b.takeDamage(f.getAttackDamage());
	f.takeDamage(30);
	f.takeDamage(-1);
	f.highFivesGuys();
	f.beRepaired(5);
	b.beRepaired(5);
	f.takeDamage(180);
	f.attack("John");
	s.beRepaired(7);

	DiamondTrap d("dynamo");

	ClapTrap* ptr = new DiamondTrap(d);
	FragTrap* fragPtr = new FragTrap(d);
	ScavTrap* scavPtr = new ScavTrap(d);

	ptr->attack("John");
	fragPtr->attack("John");
	scavPtr->attack("John");
	d.attack("John");
	a.takeDamage(d.getAttackDamage());
	d.beRepaired(5);
	d.whoAmI();
	d.highFivesGuys();
	d.guardGate();

	std::cout << std::endl;
	delete ptr;
	delete fragPtr;
	delete scavPtr;

	return 0;
}
