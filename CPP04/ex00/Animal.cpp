/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 22:27:01 by marvin            #+#    #+#             */
/*   Updated: 2025/08/28 22:27:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << GREEN << "Animal default constructor called!" << NC << std::endl;
}

Animal::Animal(const Animal& other) {
	*this = other;
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

void	Animal::makeSound() const {
	std::cout << GREEN << "Animal make sound -> hihi!" << NC << std::endl;
}

std::string	Animal::getType() const {
	return type;
}
