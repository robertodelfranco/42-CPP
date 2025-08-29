/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 22:43:46 by marvin            #+#    #+#             */
/*   Updated: 2025/08/29 18:28:40 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
	type = "Dog";
	brain = new Brain();
	std::cout << YELLOW << "Dog default constructor called!" << NC << std::endl;
}

Dog::Dog(const Dog& other)
	: Animal(other),
	brain(new Brain(*other.brain))
{
	type = other.type;
	std::cout << YELLOW << "Dog copy constructor called!" << NC << std::endl;
}

Dog&	Dog::operator=(const Dog& other) {
	std::cout << YELLOW << "Dog copy assignment constructor called!" << NC << std::endl;

	if (this != &other) {
		Animal::operator=(other);

		delete brain;

		brain = new Brain(*other.brain);
	}
	return *this;
}

Dog::~Dog() {
	delete brain;
	std::cout << YELLOW << "Dog destructor called!" << NC << std::endl;
}

void	Dog::makeSound() const {
	std::cout << YELLOW << "Woof Woof!" << NC << std::endl;
}

void	Dog::setIdea(int i, std::string idea) {
	this->brain->setIdea(i, idea);
}

std::string	Dog::getIdea(int i) {
	return this->brain->getIdea(i);
}
