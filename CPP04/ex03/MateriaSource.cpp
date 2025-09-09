/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:50:24 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/09/09 15:18:41 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : m_materias() {
	std::cout << YELLOW << "MateriaSource default constructor called!" << NC << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	std::cout << YELLOW << "MateriaSource copy constructor called!" << NC << std::endl;
	*this = other;
	// can I called m_materias[i]->clone() here?
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	std::cout << YELLOW << "MateriaSource copy assignment constructor called!" << NC << std::endl;
	if (this != &other) {
		for (int i = 0; i < 4; i++) {
			delete m_materias[i];
			m_materias[i] = other.m_materias[i];
		}
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	std::cout << YELLOW << "MateriaSource destructor called!" << NC << std::endl;
	for (int i = 0; i < 4; i++) {
		if (m_materias[i] != NULL)
			delete m_materias[i];
	}
}

void	MateriaSource::learnMateria(AMateria* m) {
	std::cout << YELLOW << "MateriaSource learnMateria function called!" << NC << std::endl;
	for (int i = 0; i < 4; i++) {
		if (m_materias[i] == NULL) {
			m_materias[i] = m;
			return ;
		}
	}
	std::cout << YELLOW << "MateriaSource inventory already full!" << NC << std::endl;
}

AMateria*	MateriaSource::createMateria(std::string const & type) {
	std::cout << YELLOW << "MateriaSource createMateria function called!" << NC << std::endl;
	AMateria* m;

	if (type == "ice")
		m = new Ice();
	else if (type == "cure")
		m = new Cure();
	else {
		std::cout << YELLOW << "Only accepted ice or cure materias!" << NC << std::endl;
		return NULL;
	}
	return m;
}
