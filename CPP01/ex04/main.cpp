/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 19:11:44 by marvin            #+#    #+#             */
/*   Updated: 2025/08/24 19:11:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int main(int argc, char **argv) {
	if (argc < 4) {
		std::cout << "Too few arguments" << std::endl;
		return 1;
	} else if (argc > 4) {
		std::cout << "Too many arguments" << std::endl;
		return 1;
	}
	stringReplace(argv[1], argv[2], argv[3]);
	return 0;
}
