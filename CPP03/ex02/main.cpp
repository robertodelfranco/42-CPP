/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 18:09:24 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/08/28 16:06:38 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() {
	ClapTrap a("John");
	ClapTrap b("Jane doe");

	std::cout << std::endl;

	FragTrap f("teste");
	FragTrap f2("Frag");

	f = f2;

	f.attack("Jane doe");
	b.takeDamage(f.getAttackDamage());
	f.takeDamage(30);
	f.takeDamage(-1);
	f.highFivesGuys();
	f.beRepaired(5);
	b.beRepaired(5);
	f.takeDamage(180);
	f.attack("John");

	std::cout << std::endl;
}
