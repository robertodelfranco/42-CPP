/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 22:27:01 by marvin            #+#    #+#             */
/*   Updated: 2025/08/29 19:01:56 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << GREEN << "Animal default constructor called!" << NC << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type) {
	std::cout << GREEN << "Animal copy constructor called!" << NC << std::endl;
}

Animal&	Animal::operator=(const Animal& other) {
	std::cout << GREEN << "Animal copy assignment constructor called!" << NC << std::endl;

	if (this != &other) {
		type = other.type;
	}
	return *this;
}

Animal::~Animal() {
	std::cout << GREEN << "Animal destructor called!" << NC << std::endl;
}

std::string	Animal::getType() const {
	return type;
}
