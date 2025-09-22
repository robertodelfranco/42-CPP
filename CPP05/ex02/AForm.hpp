/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 13:50:21 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/09/22 14:12:21 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

#define MAGENTA "\033[1;35m"
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define CYAN "\033[1;36m"
#define BLUE "\033[1;34m"
#define RED "\033[1;31m"
#define NC "\033[0m"

class Bureaucrat;

class AForm {
	private:
		const std::string name;
		bool isSigned;
		const int gradeToSign;
		const int gradeToExecute;

	protected:
		virtual void	executeAction() const = 0;
	
	public:
		AForm();
		AForm(const std::string name, const int gradeToSign, const int gradeToExecute);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual	~AForm();

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};

		void	beSigned(const Bureaucrat& b);

		void	execute(Bureaucrat const & executor) const;

		// gettters
		const std::string&	getName() const;
		bool				getIsSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif