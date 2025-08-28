/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 16:17:24 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/08/28 18:57:29 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string name)
	: ClapTrap(name + "_clap_name"),
	ScavTrap(name),
	FragTrap(name),
	m_name(name)
{
	m_hitPoints = FragTrap::m_hitPoints;
	m_energy = ScavTrap::m_energy;
	m_attackDamage = FragTrap::m_attackDamage;
	std::cout << WHITE << "DiamondTrap default constructor called" << NC << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: ClapTrap(other),
	ScavTrap(other),
	FragTrap(other),
	m_name(other.m_name)
{
	std::cout << WHITE << "DiamondTrap copy constructor called" << NC << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other) {
	std::cout << WHITE << "DiamondTrap copy assignment constructor called" << NC << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
		ScavTrap::operator=(other);
		FragTrap::operator=(other);
		m_name = other.m_name;
	}
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << WHITE << "DiamondTrap destructor called" << NC << std::endl;
}

void	DiamondTrap::attack(const std::string target) {
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI() {
	std::cout << WHITE << "DiamondTrap name " << m_name << " and ClapTrap name " << ClapTrap::m_name << NC << std::endl;
}
