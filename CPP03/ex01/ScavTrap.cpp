/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 12:09:52 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/08/28 16:00:13 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name) {
	m_hitPoints = 100;
	m_energy = 50;
	m_attackDamage = 20;
	std::cout << CYAN << "ScavTrap default constructor called" << NC << std::endl;	
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	std::cout << CYAN << "ScavTrap copy constructor called" << NC << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& other) {
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << CYAN << "ScavTrap copy assignment constructor called" << NC << std::endl;
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << CYAN << "ScavTrap destructor called" << NC << std::endl;
}

void	ScavTrap::attack(const std::string& target) {
	if (m_hitPoints > 0 && m_energy > 0) {
		m_energy -= 1;
		std::cout << CYAN << "ScavTrap " << m_name << " attacks " << target << ", causing " << m_attackDamage << " points of damage!" << NC << std::endl;
	}
	else if (m_hitPoints == 0)
		std::cout << CYAN << "ScavTrap " << m_name << " cannot attack because is already dead!" << NC << std::endl;
	else
		std::cout << CYAN << "ScavTrap " << m_name << " has no energy to attack!" << NC << std::endl;
}

void	ScavTrap::guardGate() {
	std::cout << CYAN << "ScavTrap " << m_name << " is now in Gate keeper mode!" << NC << std::endl;
}
