/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 14:39:22 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/08/26 18:37:57 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
	Fixed		a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));
	Fixed		c(Fixed(5.05f));

	std::cout << YELLOW << "\nIncrement and Decrement\n" << NC << std::endl;
	std::cout << a << std::endl;
	std::cout << "Pre-increment " << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << "Post-increment " << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << "Pre-decrement " << --a << std::endl;
	std::cout << a << std::endl;
	std::cout << "Post-decrement " << a-- << std::endl;
	std::cout << a << std::endl;

	std::cout << "a: " << a << " b: " << b << " c: " << c << std::endl;
	std::cout << YELLOW << "\nMin and Max\n" << NC << std::endl;
	std::cout << "Const Min: " << Fixed::min(a, b) << std::endl;
	std::cout << "Const Max: " << Fixed::max(a, b) << std::endl;
	std::cout << "Min: " << Fixed::min(a, c) << std::endl;
	std::cout << "Max: " << Fixed::max(a, c) << std::endl;	

	std::cout << "a: " << a << " b: " << b << " c: " << c << std::endl;
	std::cout << YELLOW << "\nComparisions\n" << NC << std::endl;
	std::cout << "a == b: " << (a == b) << std::endl;
	std::cout << "a != b: " << (a != b) << std::endl;
	std::cout << "a < b: " << (a < b) << std::endl;
	std::cout << "a > b: " << (a > b) << std::endl;
	std::cout << "a <= b: " << (a <= b) << std::endl;
	std::cout << "a >= b: " << (a >= b) << std::endl;

	std::cout << YELLOW << "\nArithmetic\n" << NC << std::endl;
	std::cout << "a + b: " << (a + b) << std::endl;
	std::cout << "a - b: " << (a - b) << std::endl;
	std::cout << "c * b: " << (c * b) << std::endl;
	std::cout << "c / b: " << (c / b) << std::endl;
	std::cout << "b / a: " << (b / a) << std::endl;

	return 0;
}
