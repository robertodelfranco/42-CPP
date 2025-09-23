/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 14:17:22 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/09/22 14:20:11 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137) {
    std::cout << RED << "ShrubberyCreationForm Default constructor called" << NC << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm(target, 145, 137) {
    std::cout << RED << "ShrubberyCreationForm Parameterized constructor called" << NC << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other) {
    std::cout << RED << "ShrubberyCreationForm Copy constructor called" << NC << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
    }
    std::cout << RED << "ShrubberyCreationForm Copy assignment operator called" << NC << std::endl;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << RED << "ShrubberyCreationForm Destructor called" << NC << std::endl;
}

void    ShrubberyCreationForm::executeAction() const {
    std::ofstream outfile((this->getName() + "_shrubbery").c_str());
    if (!outfile) {
        std::cerr << RED << "Error creating file." << NC << std::endl;
        return;
    }
    outfile << "       _-_\n"
               "    /~~   ~~\\\n"
               " /~~         ~~\\\n"
               "{               }\n"
               " \\  _-     -_  /\n"
               "   ~  \\\\ //  ~\n"
               "_- -   | | _- _\n"
               "  _ -  | |   -_\n"
               "      // \\\\\n";
    outfile.close();
    std::cout << GREEN << "Shrubbery created successfully." << NC << std::endl;
}
