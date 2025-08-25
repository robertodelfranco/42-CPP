/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:33:33 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/08/25 18:44:32 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::bitValue = 0;

Fixed::Fixed() : fixedValue(0) {}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	// Copy the original object to the new
	this->fixedValue = other.getRawBits();
}

Fixed&	Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	// Protection against auto-atribuition
	if (this != &other) {
		this->fixedValue = other.getRawBits();
	}
	// return the actual reference to the object
	return *this;
}

Fixed::~Fixed() {}
