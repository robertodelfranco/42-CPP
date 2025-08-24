/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 13:43:14 by marvin            #+#    #+#             */
/*   Updated: 2025/08/24 13:43:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) :_type(type) {
	std::cout << "Weapon " << _type << " was created!" << std::endl;
}

Weapon::~Weapon() {
	std::cout << "Weapon " << _type << " was destroyed!" << std::endl;
}

const	std::string& Weapon::getType() const {
	return (_type);
}

void	Weapon::setType(std::string type) {
	_type = type;
	std::cout << "Weapon " << _type << " has been set!" << std::endl;
}
