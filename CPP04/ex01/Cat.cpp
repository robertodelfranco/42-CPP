/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 22:32:41 by marvin            #+#    #+#             */
/*   Updated: 2025/08/29 18:30:33 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
	type = "Cat";
	brain = new Brain();
	std::cout << CYAN << "Cat default constructor called!" << NC << std::endl;
}

Cat::Cat(const Cat& other)
	: Animal(other),
	brain(new Brain(*other.brain))
{
	type = other.type;
	std::cout << CYAN << "Cat copy constructor called!" << NC << std::endl;
}

Cat&	Cat::operator=(const Cat& other) {
	std::cout << CYAN << "Cat copy assignment constructor called!" << NC << std::endl;

	if (this != &other) {
		Animal::operator=(other);

		delete brain;

		brain = new Brain(*other.brain);
	}
	return *this;
}

Cat::~Cat() {
	delete brain;
	std::cout << CYAN << "Cat destructor called!" << NC << std::endl;
}

void	Cat::makeSound() const {
	std::cout << CYAN << "Meow!" << NC << std::endl;
}

void	Cat::setIdea(int i, std::string idea) {
	this->brain->setIdea(i, idea);
}

std::string	Cat::getIdea(int i) {
	return this->brain->getIdea(i);
}
