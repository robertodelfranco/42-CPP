/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 12:43:03 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/08/22 14:51:24 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

static std::string validateInput(const std::string& prompt, const std::string& type) {
	std::string input;
	bool		valid;

	while (true)
	{
		valid = true;
		std::cout << prompt << ": ";
		std::getline(std::cin, input);
		if (std::cin.eof()) {
			std::cout << "\033[91m" << "\nExiting." << "\033[0m" << std::endl;
			std::exit(1);
		}
		if (input.empty()) {
			std::cout << "\033[91m" << "Input cannot be empty. Please try again." << "\033[0m" << std::endl;
			continue;
		}
		if (type == "number") {
			for (int i = 0; i < (int)input.length(); i++) {
				if (!std::isdigit(input[i])) {
					valid = false;
					break ;
				}
			}
			if (!valid) {
				std::cout << "\033[91m" << "Invalid input. Please enter a number." << "\033[0m" << std::endl;
				continue;
			}
			if (input.length() != 11) {
				std::cout << "\033[91m" << "Phone number must be 11 digits long. Please enter a valid number." << "\033[0m" << std::endl;
				continue;
			}
		}
		else if (type == "char") {
			for (int i = 0; i < (int)input.length(); i++) {
				if (!std::isalpha(input[i]) && !std::isspace(input[i])) {
					valid = false;
					break ;
				}
			}
			if (!valid) {
				std::cout << "\033[91m" << "Invalid input. Please enter an alphabetic character." << "\033[0m" << std::endl;
				continue;
			}
		}
		else
		{
			for (int i = 0; i < (int)input.length(); i++) {
				if (!std::isprint(input[i])) {
					valid = false;
					break ;
				}
			}
			if (!valid) {
				std::cout << "\033[91m" << "Invalid input. Please enter a valid character." << "\033[0m" << std::endl;
				continue;
			}
		}
		return input;
	}
}

void Contact::setInfo() {
	firstName = validateInput("First name", "char");
	lastName = validateInput("Last name", "char");
	nickname = validateInput("Nickname", "any");
	phoneNumber = validateInput("Phone number", "number");
	darkestSecret = validateInput("Darkest secret", "any");
	std::cout << "\033[92m" << "Input added successfully" << "\033[0m" << std::endl;
}

static std::string truncate(const std::string& str) {
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	else
		return str;
}

void	Contact::displayInfo(int index) const {
	std::cout << "|" << std::setw(2) << index + 1
		<< "|" << std::setw(10) << truncate(firstName)
		<< "|" << std::setw(10) << truncate(lastName)
		<< "|" << std::setw(10) << truncate(nickname) 
		<< "|" << std::endl;
}

void	Contact::displayExtraInfo(int index) const {
	std::cout << "ID: " << index + 1 << "\n"
		<< "First Name: " << firstName << "\n"
		<< "Last Name: " << lastName << "\n"
		<< "Nickname: " << nickname << "\n"
		<< "Phone Number: " << phoneNumber << "\n"
		<< "Darkest Secret: " << darkestSecret
		<< std::endl;
}
