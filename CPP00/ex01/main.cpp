/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 12:22:54 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/08/22 14:38:31 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"

int	main()
{
	PhoneBook phoneBook;
	std::string command;

	std::cout << "\033[96m" << "Welcome to the PhoneBook application!" << "\033[0m" << std::endl;
	while (true) {
		std::cout << "\033[93m" << "Available commands: ADD, SEARCH, EXIT" << "\033[0m" << std::endl;
		std::cout << "Enter command: ";
		std::getline(std::cin, command);

		if (std::cin.eof()) {
			std::cout << std::endl;
			break;
		}
		if (command == "EXIT")
			break;
		else if (command == "ADD")
			phoneBook.addContact();
		else if (command == "SEARCH")
			phoneBook.searchContact();
		else
		{
			std::cout << "\033[91m" << "Invalid command, please try again." << "\033[0m" << std::endl;
			std::cout << "\033[93m" << "Available commands: ADD, SEARCH, EXIT" << "\033[0m" << std::endl;
		}
	}
	std::cout << "\033[91m" << "Exiting PhoneBook application." << "\033[0m" << std::endl;
	return (0);
}
