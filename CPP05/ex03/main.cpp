/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 14:21:00 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/09/23 11:42:05 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main() {
	Intern intern;
	AForm* form1 = intern.makeForm("robotomy request", "RobotomyTarget");
	AForm* form2 = intern.makeForm("shrubbery creation", "ShrubberyTarget");
	AForm* form3 = intern.makeForm("presidential pardon", "PardonTarget");
	intern.makeForm("unknown form", "UnknownTarget");

	std::cout << "\n--- Signing Forms ---\n" << std::endl;
	Bureaucrat signer("Alice", 5);
	signer.signForm(*form1);
	signer.signForm(*form2);
	signer.signForm(*form3);

	std::cout << "\n--- Executing Forms ---\n" << std::endl;
	Bureaucrat executor("Bob", 1);
	executor.executeForm(*form1);
	executor.executeForm(*form2);
	executor.executeForm(*form3);

	delete form1;
	delete form2;
	delete form3;

	return 0;
}