/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 14:21:19 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/08/28 18:37:12 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string name) : ClapTrap(name) {
	m_hitPoints = 100;
	m_energy = 100;
	m_attackDamage = 30;
	std::cout << MAGENTA << "FragTrap default constructor called" << NC << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << MAGENTA << "FragTrap copy constructor called" << NC << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& other) {
	std::cout << MAGENTA << "FragTrap copy assignment constructor called" << NC << std::endl;

	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << MAGENTA << "FragTrap destructor called" << NC << std::endl;
}

void	FragTrap::highFivesGuys() {
	std::cout << MAGENTA << "FragTrap high fives guys!" << NC << std::endl;
}
