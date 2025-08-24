/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 21:50:04 by marvin            #+#    #+#             */
/*   Updated: 2025/08/23 21:50:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	std::cout << "Heap" << std::endl;
	Zombie* zombie = newZombie("zombie_one");

	zombie->announce();
	delete zombie;
	std::cout << std::endl;
	std::cout << "Stack" << std::endl;
	randomChump("zombie_two");
	return (0);
}
