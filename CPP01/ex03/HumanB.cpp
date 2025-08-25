/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 14:04:35 by marvin            #+#    #+#             */
/*   Updated: 2025/08/24 14:04:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
:_name(name), _weapon(NULL) {
	std::cout << "HumanB " << _name << " with no Weapon was created!" << std::endl;
}

HumanB::~HumanB() {
	if (_weapon)
		std::cout << "HumanB " << _name << " with Weapon " << _weapon->getType() << " was destroyed!" << std::endl;
	else
		std::cout << "HumanB " << _name << " with no Weapon was destroyed!" << std::endl;
}

void	HumanB::attack() {
	if (_weapon)
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " has no weapon to attack!" << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon) {
	_weapon = &weapon;
	std::cout << "HumanB " << _name << " Weapon " << _weapon->getType() << " has been set" << std::endl;
}
