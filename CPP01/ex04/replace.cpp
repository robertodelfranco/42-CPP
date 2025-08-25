/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 19:18:23 by marvin            #+#    #+#             */
/*   Updated: 2025/08/25 15:41:37 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

void	stringReplace(std::string filename, std::string s1, std::string s2) {
	if (s1.empty()) {
		std::cout << "S1 cannot be empty!" << std::endl;
		std::exit(1);
	}

	std::ifstream infile(filename.c_str());
	if (!infile) {
		std::cout << "Error ao abrir arquivo de entrada!" << std::endl;
		std::exit(1);
	}

	std::ofstream outfile((filename + ".replace").c_str());
	if (!outfile) {
		std::cout << "Error ao abrir arquivo de saída!" << std::endl;
		std::exit(1);
	}
	
	std::string	line;
	while (std::getline(infile, line)) {
		size_t	pos = 0;
		while (true) {
			size_t	find = line.find(s1, pos);
			if (find == std::string::npos) {
				outfile << line.substr(pos);
				break;
			} else {
				outfile << line.substr(pos, find - pos);
				outfile << s2;
				pos = find + s1.length();
			}
		}
		outfile << std::endl;
	}
	infile.close();
	outfile.close();
}
