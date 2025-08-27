/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:56:45 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/08/27 11:41:59 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {
	// std::cout << GREEN << "Default constructor called" << NC << std::endl;
}

Point::Point(const float f_x, const float f_y) : x(f_x), y(f_y) {
	// std::cout << GREEN << "Float constructor called" << NC << std::endl;
}

Point::Point(const Point& other) : x(other.x), y(other.y) {
	// std::cout << CYAN << "Copy constructor called" << NC << std::endl;
}

Point&	Point::operator=(const Point& other) {
	// std::cout << CYAN << "Copy assignment constructor called" << NC << std::endl;
	(void)other;
	return *this;
}

Point::~Point() {
	// std::cout << RED << "Destructor Called" << NC << std::endl;
}

Fixed	Point::getX() const {
	return x;
}

Fixed	Point::getY() const {
	return y;
}
