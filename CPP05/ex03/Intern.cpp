/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 11:20:55 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/09/23 11:46:13 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
	std::cout << WHITE << "Intern Default constructor called" << NC << std::endl;
}

Intern::Intern(const Intern& other) {
	(void)other;
	std::cout << WHITE << "Intern Copy constructor called" << NC << std::endl;
}

Intern& Intern::operator=(const Intern& other) {
	(void)other;
	std::cout << WHITE << "Intern Copy assignment operator called" << NC << std::endl;
	return *this;
}

Intern::~Intern() {
	std::cout << WHITE << "Intern Destructor called" << NC << std::endl;
}

AForm* Intern::makeForm(const std::string& name, const std::string& target) const {
	std::string formNames[3] = {
		"robotomy request",
		"shrubbery creation",
		"presidential pardon"
	};
	AForm* forms[3] = {
		new RobotomyRequestForm(target),
		new ShrubberyCreationForm(target),
		new PresidentialPardonForm(target)
	};

	for (int i = 0; i < 3; i++) {
		if (name == formNames[i]) {
			std::cout << WHITE << "Intern creates " << name << " form." << NC << std::endl;
			for (int j = 0; j < 3; j++) {
				if (j != i)
						delete forms[j];
			}
			return forms[i];
		}
	}
	for(int d = 0; d < 3; d++)
		delete forms[d];
	std::cout << WHITE << "Intern couldn't find the form: " << name << "." << NC << std::endl;
	return NULL;
}
