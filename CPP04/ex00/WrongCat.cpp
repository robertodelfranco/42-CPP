/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 22:47:15 by marvin            #+#    #+#             */
/*   Updated: 2025/08/28 22:47:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	type = "WrongCat";
	std::cout << ORANGE << "WrongCat default constructor called!" << NC << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
	*this = other;
	std::cout << ORANGE << "WrongCat copy constructor called!" << NC << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& other) {
	std::cout << ORANGE << "WrongCat copy assignment constructor called!" << NC << std::endl;

	if (this != &other) {
		WrongAnimal::operator=(other);
	}
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << ORANGE << "WrongCat destructor called!" << NC << std::endl;
}

void	WrongCat::makeSound() const {
	std::cout << ORANGE << "Meow!" << NC << std::endl;
}
