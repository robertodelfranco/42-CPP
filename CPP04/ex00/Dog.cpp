/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 22:43:46 by marvin            #+#    #+#             */
/*   Updated: 2025/08/28 22:43:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
	type = "Dog";
	std::cout << YELLOW << "Dog default constructor called!" << NC << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
	*this = other;
	std::cout << YELLOW << "Dog copy constructor called!" << NC << std::endl;
}

Dog&	Dog::operator=(const Dog& other) {
	std::cout << YELLOW << "Dog copy assignment constructor called!" << NC << std::endl;

	if (this != &other) {
		Animal::operator=(other);
	}
	return *this;
}

Dog::~Dog() {
	std::cout << YELLOW << "Dog destructor called!" << NC << std::endl;
}

void	Dog::makeSound() const {
	std::cout << YELLOW << "Woof Woof!" << NC << std::endl;
}
