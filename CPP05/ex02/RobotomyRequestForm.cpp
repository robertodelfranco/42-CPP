/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 14:10:53 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/09/22 14:17:04 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45) {
	std::cout << MAGENTA << "RobotomyRequestForm Default constructor called" << NC << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm(target, 72, 45) {
	std::cout << MAGENTA << "RobotomyRequestForm Parameterized constructor called" << NC << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other) {
	std::cout << MAGENTA << "RobotomyRequestForm Copy constructor called" << NC << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		AForm::operator=(other);
	}
	std::cout << MAGENTA << "RobotomyRequestForm Copy assignment operator called" << NC << std::endl;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << MAGENTA << "RobotomyRequestForm Destructor called" << NC << std::endl;
}

void	RobotomyRequestForm::executeAction() const {
	std::cout << CYAN << "* Drilling noises *" << NC << std::endl;
	if (rand() % 2) {
		std::cout << MAGENTA << this->getName() << " has been robotomized successfully." << NC << std::endl;
	}
	else {
		std::cout << RED << "The robotomy for " << this->getName() << " failed." << NC << std::endl;
	}
}
