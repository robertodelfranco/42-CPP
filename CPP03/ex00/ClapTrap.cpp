/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:56:48 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/08/27 18:34:13 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string name)
	: m_name(name),
	m_hitPoints(10),
	m_energy(10),
	m_attackDamage(0) {
	std::cout << GREEN << "Default constructor called" << NC << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
	: m_name(other.m_name),
	m_hitPoints(other.m_hitPoints),
	m_energy(other.m_energy),
	m_attackDamage(other.m_attackDamage) {
	std::cout << CYAN << "Copy constructor called" << NC << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& other) {
	std::cout << CYAN << "Copy assignment constructor called" << NC << std::endl;

	if (this != &other) {
		this->m_name = other.m_name;
		this->m_hitPoints = other.m_hitPoints;
		this->m_energy = other.m_energy;
		this->m_attackDamage = other.m_attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << RED << "Destructor called" << NC << std::endl;
}

void	ClapTrap::attack(const std::string& target) {
	if (m_energy > 0 && m_hitPoints > 0) {
		m_energy -= 1;
		std::cout << YELLOW << "ClapTrap " << m_name << " attacks " << target << ", causing " << m_attackDamage << " points of damage!" << NC << std::endl;
	}
	else if (m_hitPoints == 0)
		std::cout << RED << "ClapTrap " << m_name << " cannot attack because is already dead!" << NC << std::endl;
	else
		std::cout << RED << "ClapTrap " << m_name << " has no energy to attack!" << NC << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (amount > INT_MAX) {
		std::cout << RED << "ClapTrap doesn't accept negative numbers!" << NC << std::endl;
		return ;
	}
	if (m_hitPoints > 0) {
		m_hitPoints -= amount;
		if (m_hitPoints < 0)
			m_hitPoints = 0;
		std::cout << YELLOW << "ClapTrap " << m_name << " has taken " << amount << " points of damage and now has " << m_hitPoints << " points of life!" << NC << std::endl;
	}
	else
		std::cout << RED << "Claptrap " << m_name << " is already dead!" << NC << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (amount > INT_MAX) {
		std::cout << RED << "ClapTrap doesn't accept negative numbers!" << NC << std::endl;
		return ;
	}
	if (m_energy > 0 && m_hitPoints > 0) {
		m_energy -= 1;
		m_hitPoints += amount;
		std::cout << YELLOW << "ClapTrap " << m_name << " has restore " << amount << " points and now has " << m_hitPoints << " of life!" << NC << std::endl;
	}
	else if (m_hitPoints == 0)
		std::cout << RED << "ClapTrap " << m_name << " is dead and cannot be repaired!" << NC << std::endl;
	else
		std::cout << RED << "ClapTrap " << m_name << " has no energy to be repaired!" << NC << std::endl;
}

int	ClapTrap::getAttackDamage() {
	return m_attackDamage;
}

void	ClapTrap::setAttackDamage(unsigned int damage) {
	if (damage > INT_MAX) {
		std::cout << RED << "ClapTrap doesn't accept negative numbers!" << NC << std::endl;
		return ;
	}
	std::cout << YELLOW << "ClapTrap " << m_name << " has now " << damage << " of attack damage!" << NC << std::endl;
	m_attackDamage = damage;
}
