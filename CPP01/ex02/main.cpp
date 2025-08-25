/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 22:47:23 by marvin            #+#    #+#             */
/*   Updated: 2025/08/23 22:47:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main() {
	std::string hi = "HI THIS IS BRAIN";
	std::string* stringPTR = &hi;
	std::string& stringREF = hi;

	std::cout << "Memories" << std::endl;
	std::cout << "The memory address of the string variable -> " << &hi << std::endl;
	std::cout << "The memory address held by stringPTR -> " << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF -> " << &stringREF << std::endl;
	
	std::cout << "\nValues" << std::endl;
	std::cout << "The value of the string variable -> " << hi << std::endl;
	std::cout << "The value pointed to by stringPTR -> " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF -> " << stringREF << std::endl;
}
