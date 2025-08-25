/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 22:17:23 by marvin            #+#    #+#             */
/*   Updated: 2025/08/23 22:17:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	int	N = 5;
	Zombie* zombies = zombieHorde(N, "Jane doe");

	for (int i = 0; i < N; i++)
		zombies[i].announce();

	delete[] zombies;
}
