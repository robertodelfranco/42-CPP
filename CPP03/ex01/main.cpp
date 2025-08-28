/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 18:09:24 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/08/28 14:08:15 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
	ClapTrap a("John");
	ClapTrap b("Jane doe");

	std::cout << std::endl;
	
	a.setAttackDamage(3);
	a.setAttackDamage(-3);
	b.setAttackDamage(2);

	std::cout << std::endl;
	
	a.attack("Jane doe");
	a.takeDamage(-9);
	b.takeDamage(a.getAttackDamage());
	b.attack("John");
	a.takeDamage(b.getAttackDamage());
	b.beRepaired(1);
	b.beRepaired(-1);
	a.attack("Jane doe");
	b.takeDamage(a.getAttackDamage());
	b.attack("John");
	b.beRepaired(8);
	a.attack("Jane doe");
	b.takeDamage(a.getAttackDamage());
	a.beRepaired(2);
	b.beRepaired(5);

	ScavTrap s("Scav");

	s.attack("Jane doe");
	b.takeDamage(s.getAttackDamage());
	s.takeDamage(30);
	s.takeDamage(-1);
	s.guardGate();
	s.beRepaired(5);
	b.beRepaired(5);
	s.takeDamage(180);
	s.attack("John");

	std::cout << std::endl;
}
