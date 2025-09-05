/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 19:17:52 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/09/05 19:26:21 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(const std::string name) : m_name(name) {
	std::cout << ORANGE << "Character default constructor called!" << NC << std::endl;
}

Character::Character(const Character& other) {
	std::cout << ORANGE << "Character copy constructor called!" << NC << std::endl;
}

Character&	Character::operator=(const Character& other) {
	std::cout << ORANGE << "Character copy assignment called!" << NC << std::endl;
}

Character::~Character() {
	std::cout << ORANGE << "Character destructor called!" << NC << std::endl;
}
