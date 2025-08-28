/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 18:09:24 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/08/28 15:59:30 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
	ClapTrap a("John");
	ClapTrap b("Jane doe");

	std::cout << std::endl;

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
