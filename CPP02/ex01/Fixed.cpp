/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:33:33 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/08/25 19:31:51 by rdel-fra         ###   ########.fr       */
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
	// Copy the original object to the new
	this->fixedValue = other.getRawBits();
}

Fixed&	Fixed::operator=(const Fixed& other) {
	std::cout << CYAN << "Copy assignment operator called" << NC << std::endl;
	// Protection against auto-atribuition
	if (this != &other) {
		this->fixedValue = other.getRawBits();
	}
	// return the actual reference to the object
	return *this;
}

Fixed::~Fixed() {
	std::cout << RED << "Destructor called" << NC << std::endl;
}

int	Fixed::getRawBits() const {
	return fixedValue;
}

void	Fixed::setRawBits(int const raw) {
	fixedValue = raw;
}

float	Fixed::toFloat(void) const {
	return ((float)fixedValue / (1 << fractionalBitValue));
}

int		Fixed::toInt(void) const {
	return (fixedValue >> fractionalBitValue);
}

std::ostream&	operator<<(std::ostream& less, const Fixed& object) {
	less << object.toFloat();
	return less;
}
