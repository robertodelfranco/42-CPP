/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 20:02:26 by marvin            #+#    #+#             */
/*   Updated: 2025/08/24 20:02:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main() {
	Harl h = Harl();

	std::cout << "Level INFO" << std::endl;
	h.complain("INFO");
	std::cout << std::endl;
	std::cout << "Level ERROR" << std::endl;
	h.complain("ERROR");
	std::cout << std::endl;
	std::cout << "Level WARNING" << std::endl;
	h.complain("WARNING");
	std::cout << std::endl;
	std::cout << "Level DEBUG" << std::endl;
	h.complain("DEBUG");
	std::cout << std::endl;
	std::cout << "Level EMPTY" << std::endl;
	h.complain("");
}
