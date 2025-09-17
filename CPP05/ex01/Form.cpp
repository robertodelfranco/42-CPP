#include "Form.hpp"

Form::Form() : name("Default"), isSigned(false), gradeToSign(150), gradeToExecute(150) {
	std::cout << YELLOW << "Form Default constructor called" << NC << std::endl;
}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute)
	: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
	std::cout << GREEN << "Form Parameterized constructor called" << NC << std::endl;
}

Form::Form(const Form& other)
	: name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {
	std::cout << CYAN << "Form Copy constructor called" << NC << std::endl;
}

Form& Form::operator=(const Form& other) {
	if (this != &other) {
		this->isSigned = other.isSigned;
	}
	std::cout << CYAN << "Form Copy assignment operator called" << NC << std::endl;
	return *this;
}

Form::~Form() {
	std::cout << RED << "Form Destructor called" << NC << std::endl;
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

void Form::beSigned(const Bureaucrat& b) {
	if (this->isSigned) {
		std::cout << MAGENTA << b.getName() << " couldn't sign " << this->name << " because it is already signed." << NC << std::endl;
		return ;
	}
	if (b.getGrade() > this->gradeToSign) {
		throw Form::GradeTooLowException();
	}
	this->isSigned = true;
}

const std::string&	Form::getName() const {
	return this->name;
}

bool	Form::getIsSigned() const {
	return this->isSigned;
}

int	Form::getGradeToSign() const {
	return this->gradeToSign;
}

int	Form::getGradeToExecute() const {
	return this->gradeToExecute;
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
	os << "Form " << form.getName() << ", is signed: " << form.getIsSigned() << ", grade to sign: " << form.getGradeToSign() << ", grade to execute: " << form.getGradeToExecute() << ".";
	return os;
}
