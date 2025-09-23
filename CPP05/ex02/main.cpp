/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 14:21:00 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/09/23 11:15:45 by rdel-fra         ###   ########.fr       */
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
    jane.signForm(robotomyForm);
    john.signForm(robotomyForm);
    jane.signForm(shrubberyForm);
    john.signForm(shrubberyForm);
    jane.signForm(pardonForm);
    john.signForm(pardonForm);

    std::cout << "\n--- Executing Forms ---\n" << std::endl;
    john.executeForm(robotomyForm);
    jane.executeForm(robotomyForm);
    john.executeForm(shrubberyForm);
    jane.executeForm(shrubberyForm);
    john.executeForm(pardonForm);
    jane.executeForm(pardonForm);

    return 0;
}