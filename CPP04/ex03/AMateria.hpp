/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 13:06:07 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/09/05 17:16:06 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

# define ORANGE "\033[38;5;214m"
# define MAGENTA "\033[95m"
# define YELLOW "\033[93m"
# define WHITE "\033[97m"
# define GREEN "\033[92m"
# define CYAN "\033[96m"
# define RED "\033[91m"
# define NC "\033[0m"

class AMateria {
	protected:
		std::string const m_type;

	public:
		AMateria(std::string const & type);
		AMateria(const AMateria& other);
		AMateria& operator=(const AMateria& other);
		virtual ~AMateria();

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
		std::string const & getType() const;
};

#endif /* AMATERIA_HPP */