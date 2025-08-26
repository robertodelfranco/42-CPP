/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 12:28:00 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/08/26 18:34:42 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::fractionalBitValue = 8;

Fixed::Fixed() : fixedValue(0) {
	std::cout << GREEN << "Default constructor called" << NC << std::endl;
}

Fixed::Fixed(const int value) {
	std::cout << GREEN << "Int constructor called" << NC << std::endl;
	fixedValue = value << fractionalBitValue;
}

Fixed::Fixed(const float value) {
	std::cout << GREEN << "Float constructor called" << NC << std::endl;
	fixedValue = roundf(value * (1 << fractionalBitValue));
}

Fixed::Fixed(const Fixed& other) {
	std::cout << CYAN << "Copy constructor called" << NC << std::endl;
	this->fixedValue = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << CYAN << "Copy assignment operator called" << NC << std::endl;
	if (this != &other) {
		this->fixedValue = other.getRawBits();
	}
	return *this;
}

Fixed::~Fixed() {
	std::cout << RED << "Destructor called" << NC << std::endl;
}

int	Fixed::getRawBits(void) const {
	return fixedValue;
}

void	Fixed::setRawBits(int const raw) {
	fixedValue = raw;
}

int	Fixed::toInt(void) const {
	return (fixedValue >> fractionalBitValue);
}

float	Fixed::toFloat(void) const {
	return ((float)fixedValue / (1 << fractionalBitValue));
}

std::ostream&	operator<<(std::ostream& less, const Fixed& object) {
	return (less << object.toFloat());
}

// comparasion it's bool

bool	Fixed::operator>(const Fixed& object) const {
	return (fixedValue > object.fixedValue);
}

bool	Fixed::operator<(const Fixed& object) const {
	return (fixedValue < object.fixedValue);
}

bool	Fixed::operator==(const Fixed& object) const {
	return (fixedValue == object.fixedValue);
}

bool	Fixed::operator!=(const Fixed& object) const {
	return (fixedValue != object.fixedValue);
}

bool	Fixed::operator>=(const Fixed& object) const {
	return (fixedValue >= object.fixedValue);
}

bool	Fixed::operator<=(const Fixed& object) const {
	return (fixedValue <= object.fixedValue);
}

// arithmetic and increment/decrement are Fixed

Fixed	Fixed::operator+(const Fixed& object) const {
	Fixed	temp;

	temp.setRawBits(fixedValue + object.fixedValue);
	return temp;
}

Fixed	Fixed::operator-(const Fixed& object) const {
	Fixed	temp;

	temp.setRawBits(fixedValue - object.fixedValue);
	return temp;
}

Fixed	Fixed::operator*(const Fixed& object) const {
	Fixed	temp;

	temp.setRawBits(((int64_t)fixedValue * object.fixedValue) >> fractionalBitValue);
	return temp;
}

Fixed	Fixed::operator/(const Fixed& object) const {
	Fixed	temp;

	if (object.fixedValue == 0) {
		std::cout << "Error: Division by zero" << std::endl;
		return temp;
	}
	temp.setRawBits(((int64_t)fixedValue << fractionalBitValue) / object.fixedValue);
	return temp;
}

Fixed&	Fixed::operator++(void) {
	++fixedValue;
	return *this;
}

Fixed	Fixed::operator++(int) {
	Fixed	temp = *this;

	this->fixedValue++;
	return temp;
}

Fixed&	Fixed::operator--() {
	--fixedValue;
	return *this;
}

Fixed	Fixed::operator--(int) {
	Fixed	temp = *this;

	this->fixedValue--;
	return temp;
}

// min and max are Fixed/const/static depends of subject

Fixed&	Fixed::min(Fixed& a, Fixed& b) {
	if (a < b)
		return a;
	return b;
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b) {
	if (a < b)
		return a;
	return b;
}

Fixed&	Fixed::max(Fixed& a, Fixed& b) {
	if (a > b)
		return a;
	return b;
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b) {
	if (a > b)
		return a;
	return b;
}
