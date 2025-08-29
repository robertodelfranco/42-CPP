/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 22:45:49 by marvin            #+#    #+#             */
/*   Updated: 2025/08/29 16:26:05 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
	std::cout << RED << "WrongAnimal default constructor called!" << NC << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	*this = other;
	std::cout << RED << "WrongAnimal copy constructor called!" << NC << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& other) {
	std::cout << RED << "WrongAnimal copy assignment constructor called!" << NC << std::endl;

	if (this != &other) {
		type = other.type;
	}
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << RED << "WrongAnimal destructor called!" << NC << std::endl;
}

void	WrongAnimal::makeSound() const {
	std::cout << RED << "WrongAnimal make sound -> hi!" << NC << std::endl;
}

std::string	WrongAnimal::getType() const {
	return type;
}
