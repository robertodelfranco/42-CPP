/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 13:50:18 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/09/23 11:59:51 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("Default"), grade(150) {
	std::cout << GREEN << "Bureaucrat Default constructor called" << NC << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade)  {
	if (grade < 1) throw Bureaucrat::GradeTooHighException();
	if (grade > 150) throw Bureaucrat::GradeTooLowException();
	std::cout << GREEN << "Bureaucrat Parameterized constructor called" << NC << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {
	std::cout << GREEN << "Bureaucrat Copy constructor called" << NC << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		this->grade = other.grade;
	}
	std::cout << GREEN << "Bureaucrat Copy assignment operator called" << NC << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << GREEN << "Bureaucrat Destructor called" << NC << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

void	Bureaucrat::signForm(AForm& form) const {
	if (form.getIsSigned()) {
		std::cout << GREEN << this->name << " couldn't sign " << form.getName() << " because it is already signed." << NC << std::endl;
		return ;
	}
	form.beSigned(*this);
	if (form.getIsSigned())
		std::cout << GREEN << this->name << " signed " << form.getName() << NC << std::endl;
}

void	Bureaucrat::executeForm(AForm const & form) const {
	form.execute(*this);
	std::cout << GREEN << this->name << " executed " << form.getName() << NC << std::endl;
}

const std::string& Bureaucrat::getName() const {
	return this->name;
}

int Bureaucrat::getGrade() const {
	return this->grade;
}

void Bureaucrat::incrementGrade() {
	if (this->grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade--;
}

void Bureaucrat::decrementGrade() {
	if (this->grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->grade++;
}

std::ostream&	operator<<(std::ostream& less, const Bureaucrat& b) {
	return less << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
}
