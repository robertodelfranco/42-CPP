/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 17:00:57 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/09/09 15:15:55 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() {
	std::cout << MAGENTA << "AMateria default constructor called!" << NC << std::endl;
}

AMateria::AMateria(std::string const & type) : m_type(type) {
	std::cout << MAGENTA << "AMateria type constructor called!" << NC << std::endl;
}

AMateria::AMateria(const AMateria& other) {
	std::cout << MAGENTA << "AMateria copy constructor called" << NC << std::endl;
	*this = other;
}

AMateria&	AMateria::operator=(const AMateria& other) {
	std::cout << MAGENTA << "AMateria copy assignment constructor called!" << NC << std::endl;

	if (this != &other) {
		this->m_type = other.m_type;
	}
	return (*this);
}

AMateria::~AMateria() {
	std::cout << MAGENTA << "AMateria destructor called!" << NC << std::endl;
}

void	AMateria::use(ICharacter& target) {
	(void)target;
}

std::string	const & AMateria::getType() const {
	return m_type;
}
