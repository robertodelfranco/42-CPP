/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 19:17:52 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/09/09 15:22:08 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(const std::string name) : m_name(name), m_inventory() {
	std::cout << ORANGE << "Character default constructor called!" << NC << std::endl;
}

Character::Character(const Character& other) {
	std::cout << ORANGE << "Character copy constructor called!" << NC << std::endl;
	*this = other;
}

Character&	Character::operator=(const Character& other) {
	std::cout << ORANGE << "Character copy assignment called!" << NC << std::endl;
	if (this != &other) {
		for (int i = 0; i < 4; i++) {
			delete m_inventory[i];
			m_inventory[i] = other.m_inventory[i];
		}
	}
	return *this;
}

Character::~Character() {
	std::cout << ORANGE << "Character destructor called!" << NC << std::endl;
	for(int i = 0; i < 4; i++) {
		if (m_inventory[i] != NULL)
			delete m_inventory[i];
	} 
}

std::string const & Character::getName() const {
	return m_name;
}

void	Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (m_inventory[i])
			continue ;
		m_inventory[i] = m;
		std::cout << "Materia " << m->getType() << " equiped in slot " << i << std::endl;
		return ;
	}
	std::cout << ORANGE << "Inventory full!" << NC <<  std::endl;
}

void	Character::unequip(int idx) {
	if (idx < 0 || idx > 3) {
		std::cout << "Index out of range" << std::endl;
		return ;
	}
	m_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target) {
	if (m_inventory[idx] == NULL) {
		std::cout << ORANGE << "slot idx " << idx << " is empty!" << NC << std::endl;
		return ;
	}
	m_inventory[idx]->use(target);
}
