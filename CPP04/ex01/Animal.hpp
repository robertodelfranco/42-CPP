/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 22:12:24 by marvin            #+#    #+#             */
/*   Updated: 2025/08/29 16:21:31 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

#define YELLOW "\033[93m"
#define WHITE "\033[97m"
#define GREEN "\033[92m"
#define CYAN "\033[96m"
#define NC "\033[0m"

class Animal {
	protected:
		std::string type;

	public:
		Animal();
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		virtual ~Animal();

		virtual void	makeSound() const;
		std::string		getType() const;
};

#endif /* ANIMAL_HPP */
