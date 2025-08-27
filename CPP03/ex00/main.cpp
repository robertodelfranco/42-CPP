/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 18:09:24 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/08/27 18:41:01 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

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
	a.attack("Jane doe");
	b.takeDamage(a.getAttackDamage());
	a.attack("Jane doe");
	b.takeDamage(a.getAttackDamage());
	b.beRepaired(1);
	b.beRepaired(-1);
	a.attack("Jane doe");
	b.takeDamage(a.getAttackDamage());
	b.attack("John");
	b.beRepaired(8);
	a.attack("Jane doe");
	b.takeDamage(a.getAttackDamage());
	a.beRepaired(2);
	a.beRepaired(2);
	a.beRepaired(2);
	a.beRepaired(2);
	a.beRepaired(2);
	a.beRepaired(2);
	a.beRepaired(2);
	a.attack("Jane doe");
	b.takeDamage(a.getAttackDamage());
	b.beRepaired(5);
	std::cout << std::endl;
}
