/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:15:27 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/09/09 16:18:23 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
	std::cout << CYAN << "Ice default constructor called!" << NC << std::endl;
}

Ice::Ice(const Ice& other) {
	std::cout << CYAN << "Ice copy constructor called!" << NC << std::endl;
	*this = other;
}

Ice& Ice::operator=(const Ice& other) {
	std::cout << CYAN << "Ice copy assignment constructor called!" << NC << std::endl;
	if (this != &other) {
		AMateria::operator=(other);
	}
	return (*this);
}

Ice::~Ice() {
	std::cout << CYAN << "Defaut destructor called!" << NC << std::endl;
}

AMateria*	Ice::clone() const {
	return new Ice(*this);
}

void	Ice::use(ICharacter& target) {
	std::cout << CYAN << "* shoots an ice bolt at " << target.getName() << " *" << NC << std::endl;
}
