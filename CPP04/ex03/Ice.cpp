/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:15:27 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/09/09 15:17:10 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() {
	std::cout << CYAN << "Ice default constructor called!" << NC << std::endl;
}

Ice::Ice(const Ice& other) {
	std::cout << CYAN << "Ice copy constructor called!" << NC << std::endl;
	*this = other;
}

Ice& Ice::operator=(const Ice& other) {
	std::cout << CYAN << "Ice copy assignment constructor called!" << NC << std::endl;
	if (this != &other) {
		*this = other;
	}
	return (*this);
}

Ice::~Ice() {
	std::cout << CYAN << "Defaut destructor called!" << NC << std::endl;
}

AMateria*	Ice::clone() const {
	AMateria* other = new Ice();
	return other;
}

void	Ice::use(ICharacter& target) {
	std::cout << CYAN << "* shoots an ice bolt at " << target.getName() << " *" << NC << std::endl;
}
