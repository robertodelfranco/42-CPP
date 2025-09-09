/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 19:17:52 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/09/09 18:11:50 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(const std::string name) : m_name(name) {
	std::cout << ORANGE << "Character default constructor called!" << NC << std::endl;
	for (int i = 0; i < 4; i++) {
		m_inventory[i] = NULL;
	}

	for (int i = 0; i < 100; i++) {
		m_floorMaterial[i] = NULL;
	}
}

Character::Character(const Character& other) {
	std::cout << ORANGE << "Character copy constructor called!" << NC << std::endl;

	for (int i = 0; i < 4; i++) {
		m_inventory[i] = NULL;
	}
	
	for (int i = 0; i < 100; i++) {
		m_floorMaterial[i] = NULL;
	}
	
	*this = other;
}

Character&	Character::operator=(const Character& other) {
	std::cout << ORANGE << "Character copy assignment called!" << NC << std::endl;
	if (this != &other) {
		this->m_name = other.m_name;

		for (int i = 0; i < 4; i++) {
			if (m_inventory[i] != NULL) {
				delete m_inventory[i];
				m_inventory[i] = NULL;
			}
			if (other.m_inventory[i] != NULL) {
				m_inventory[i] = other.m_inventory[i]->clone();
			}
		}

		for (int i = 0; i < 100; i++) {
			if (m_floorMaterial[i] != NULL) {
				delete m_floorMaterial[i];
				m_floorMaterial[i] = NULL;
			}
			if (other.m_floorMaterial[i] != NULL) {
				m_floorMaterial[i] = other.m_floorMaterial[i]->clone();
			}
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

	for (int i = 0; i < 100; i++) {
		if (m_floorMaterial[i] != NULL)
			delete m_floorMaterial[i];
	}
}

std::string const & Character::getName() const {
	return m_name;
}

void	Character::equip(AMateria* m) {
	if (!m) {
		std::cout << ORANGE << "Cannot equip NULL material" << NC << std::endl;
		return ;
	}

	for (int i = 0; i < 4; i++) {
		if (m_inventory[i])
			continue ;
		m_inventory[i] = m;
		std::cout << "Materia " << m->getType() << " equiped in slot " << i << std::endl;
		return ;
	}

	std::cout << ORANGE << "Inventory full! Deleting materia " << m->getType() << NC << std::endl;
	delete m;
}

void	Character::unequip(int idx) {
	if (idx < 0 || idx > 3) {
		std::cout << ORANGE << "Index out of range" << NC << std::endl;
		return ;
	}

	for (int i = 0; i < 100; i++) {
		if (m_floorMaterial[i] == NULL) {
			m_floorMaterial[i] = m_inventory[idx];
			break ;
		}
	}

	m_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > 3) {
		std::cout << ORANGE << "Index out of range!" << NC << std::endl;
		return ;
	}
	if (m_inventory[idx] == NULL) {
		std::cout << ORANGE << "slot idx " << idx << " is empty!" << NC << std::endl;
		return ;
	}
	m_inventory[idx]->use(target);
}
