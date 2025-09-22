/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 13:49:54 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/09/22 14:13:58 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", 25, 5) {
	std::cout << CYAN << "PresidentialPardonForm Default constructor called" << NC << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm(target, 25, 5) {
	std::cout << CYAN << "PresidentialPardonForm Parameterized constructor called" << NC << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other) {
	std::cout << CYAN << "PresidentialPardonForm Copy constructor called" << NC << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this != &other) {
		AForm::operator=(other);
	}
	std::cout << CYAN << "PresidentialPardonForm Copy assignment operator called" << NC << std::endl;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << CYAN << "PresidentialPardonForm Destructor called" << NC << std::endl;
}

void PresidentialPardonForm::executeAction() const {
	std::cout << CYAN << "Informs that " << this->getName() << " has been pardoned by Zaphod Beeblebrox." << NC << std::endl;
}
