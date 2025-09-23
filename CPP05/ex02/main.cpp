/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 14:21:00 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/09/23 12:02:09 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    Bureaucrat john("John", 5);
    Bureaucrat jane("Jane", 137);

    RobotomyRequestForm robotomyForm("RobotomyTarget");
    ShrubberyCreationForm shrubberyForm("ShrubberyTarget");
    PresidentialPardonForm pardonForm("PardonTarget");

    std::cout << "\n--- Signing Forms ---\n" << std::endl;
    try {
        jane.signForm(robotomyForm);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    try {
        john.signForm(robotomyForm);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    try {
        jane.signForm(shrubberyForm);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    try {
        john.signForm(shrubberyForm);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    try {
        jane.signForm(pardonForm);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    try {
        john.signForm(pardonForm);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n--- Executing Forms ---\n" << std::endl;
    try {
        john.executeForm(robotomyForm);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    try {
        jane.executeForm(robotomyForm);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    try {
        john.executeForm(shrubberyForm);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    try {
        jane.executeForm(shrubberyForm);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    try {
        john.executeForm(pardonForm);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    try {
        jane.executeForm(pardonForm);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}