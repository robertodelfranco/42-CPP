/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 22:32:41 by marvin            #+#    #+#             */
/*   Updated: 2025/08/28 22:32:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
	type = "Cat";
	std::cout << CYAN << "Cat default constructor called!" << NC << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
	*this = other;
	std::cout << CYAN << "Cat copy constructor called!" << NC << std::endl;
}

Cat&	Cat::operator=(const Cat& other) {
	std::cout << CYAN << "Cat copy assignment constructor called!" << NC << std::endl;

	if (this != &other) {
		Animal::operator=(other);
	}
	return *this;
}

Cat::~Cat() {
	std::cout << CYAN << "Cat destructor called!" << NC << std::endl;
}

void	Cat::makeSound() const {
	std::cout << CYAN << "Meow!" << NC << std::endl;
}
