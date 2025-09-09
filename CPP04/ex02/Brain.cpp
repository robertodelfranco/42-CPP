/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:44:57 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/09/09 18:02:38 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << BLUE << "Brain default constructor called" << NC << std::endl;
}

Brain::Brain(const Brain& other) {
	for (int i = 0; i < 100; i++) {
		ideas[i] = other.ideas[i];
	}
	std::cout << BLUE << "Brain copy constructor called" << NC << std::endl;
}

Brain&	Brain::operator=(const Brain& other) {
	std::cout << BLUE << "Brain copy assignment constructor called" << NC << std::endl;

	if (this != &other) {
		for (int i = 0; i < 100; i++) {
			this->ideas[i] = other.ideas[i];
		}
	}
	return *this;
}

Brain::~Brain() {
	std::cout << BLUE << "Brain destructor called" << NC << std::endl;
}

void	Brain::setIdea(int i, std::string idea) {
	if (i >= 0 && i < 100) {
		std::cout << BLUE << "Brain setIdea called!" << NC << std::endl;
		this->ideas[i] = idea;
	}
	else {
		std::cout << BLUE << "setIdea index out of range!" << NC << std::endl;
		return ;
	}
}

std::string	Brain::getIdea(int i) {
	if (i >= 0 && i < 100 && ideas[i].empty()) {
		return "The index don't have any string on it!";
	}
	else if (i >= 0 && i < 100) {
		std::cout << BLUE << "Brain getIdea called!" << NC << std::endl;
		return ideas[i];
	}
	else {
		std::cout << BLUE << "getIdea index out of range!" << NC << std::endl;
		return "Invalid index!";
	}
}
