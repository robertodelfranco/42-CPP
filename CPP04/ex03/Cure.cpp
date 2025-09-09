/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:03:32 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/09/09 16:31:42 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
	std::cout << GREEN << "Cure default constructor called!" << NC << std::endl;
}

Cure::Cure(const Cure& other) {
	std::cout << GREEN << "Cure copy constructor called!" << NC << std::endl;
	*this = other;
}

Cure&	Cure::operator=(const Cure& other) {
	std::cout << GREEN << "Cure copy assignment constructor called!" << NC << std::endl;
	if (this != &other) {
		AMateria::operator=(other);
	}
	return (*this);
}

Cure::~Cure() {
	std::cout << GREEN << "Default destructor called!" << NC << std::endl;
}

AMateria*	Cure::clone() const {
	return new Cure(*this);
}

void	Cure::use(ICharacter& target) {
	std::cout << GREEN << "* heals " << target.getName() << "'s wounds *" << NC << std::endl;
}
