/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 17:00:57 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/09/05 18:58:12 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) {
	std::cout << GREEN << "AMateria default constructor called!" << NC << std::endl;
}

AMateria::AMateria(const AMateria& other) {
	std::cout << GREEN << "AMateria copy constructor called" << NC << std::endl;
	*this = other;
}

AMateria&	AMateria::operator=(const AMateria& other) {
	std::cout << GREEN << "AMateria copy assignment constructor called!" << NC << std::endl;

	if (this != &other) {
		this->m_type = other.m_type;
	}
	return (*this);
}

AMateria::~AMateria() {
	std::cout << GREEN << "AMateria destructor called!" << NC << std::endl;
}

void	AMateria::use(ICharacter& target) {
	(void)target;
}

std::string	const & AMateria::getType() const {
	return m_type;
}
