/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 18:13:31 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/08/22 14:47:25 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : currentIndex(0), count(0) {}

PhoneBook::~PhoneBook() {}

void PhoneBook::addContact() {
	contacts[currentIndex % 8].setInfo();
	currentIndex++;
	if (count < 8)
		count++;
}

void PhoneBook::searchContact() {
	if (count == 0) {
		std::cout << "No contacts available." << std::endl;
		return;
	}
	std::cout << "Contacts in PhoneBook:" << std::endl;
	std::cout << "|" << std::setw(2) << "ID" 
        << "|" << std::setw(10) << "First Name"
        << "|" << std::setw(10) << "Last Name" 
        << "|" << std::setw(10) << "Nickname"
        << "|" << std::endl;
    for (int i = 0; i < count; i++) {
        contacts[i].displayInfo(i);
    }
	searchContactByIndex();
}

void PhoneBook::searchContactByIndex() {
	int			index;
	std::string input;

	while (true)
	{
		std::cout << "Enter an index beetween 1 and " << count << ": ";
		std::getline(std::cin, input);
		if (std::cin.eof()) {
			std::cout << "\033[91m" << "\nExiting." << "\033[0m" << std::endl;
			std::exit(1);
		}
		if (std::cin.fail() || input.length() > 1 || !std::isdigit(input[0])) {
			std::cout << "\033[91m" << "Invalid input. Please enter a valid index." << "\033[0m" << std::endl;
			continue;
		}
		index = input[0] - '0';
		if (index < 1 || index > count) {
			std::cout << "\033[91m" << "Invalid index. Please enter an index between 1 and " << count << "." << "\033[0m" << std::endl;
			continue;
		}
		break;
	}
	std::cout << "-----------------------------" << std::endl;
	contacts[index - 1].displayExtraInfo(index - 1);
	std::cout << "-----------------------------" << std::endl;
}
