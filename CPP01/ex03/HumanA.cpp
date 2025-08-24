/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 13:56:20 by marvin            #+#    #+#             */
/*   Updated: 2025/08/24 13:56:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon)
: _name(name), _weapon(weapon) {
	std::cout << "HumanA " << _name << " with Weapon " << _weapon.getType() << " was created!" << std::endl;
}

HumanA::~HumanA() {
	std::cout << "HumanA " << _name << " with Weapon " << _weapon.getType() << " was destroyed!" << std::endl;
}

void	HumanA::attack() {
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
