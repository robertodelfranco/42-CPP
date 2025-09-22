/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 13:50:25 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/09/22 13:53:25 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("Default"), isSigned(false), gradeToSign(150), gradeToExecute(150) {
	std::cout << YELLOW << "AForm Default constructor called" << NC << std::endl;
}

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExecute)
	: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	std::cout << YELLOW << "AForm Parameterized constructor called" << NC << std::endl;
}

AForm::AForm(const AForm& other)
	: name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {
	std::cout << YELLOW << "AForm Copy constructor called" << NC << std::endl;
}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other) {
		this->isSigned = other.isSigned;
	}
	std::cout << YELLOW << "AForm Copy assignment operator called" << NC << std::endl;
	return *this;
}

AForm::~AForm() {
	std::cout << YELLOW << "AForm Destructor called" << NC << std::endl;
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

void AForm::beSigned(const Bureaucrat& b) {
	if (this->isSigned) {
		std::cout << YELLOW << b.getName() << " couldn't sign " << this->name << " because it is already signed." << NC << std::endl;
		return ;
	}
	if (b.getGrade() > this->getGradeToSign()) {
		throw AForm::GradeTooLowException();
	}
	this->isSigned = true;
}

void	AForm::execute(Bureaucrat const & executor) const {
	if (executor.getGrade() > this->getGradeToExecute()) {
		throw AForm::GradeTooLowException();
	}
	executeAction();
}

const std::string&	AForm::getName() const {
	return this->name;
}

bool	AForm::getIsSigned() const {
	return this->isSigned;
}

int	AForm::getGradeToSign() const {
	return this->gradeToSign;
}

int	AForm::getGradeToExecute() const {
	return this->gradeToExecute;
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
	os << "AForm " << form.getName() << ", is signed: " << form.getIsSigned() << ", grade to sign: " << form.getGradeToSign() << ", grade to execute: " << form.getGradeToExecute() << ".";
	return os;
}
