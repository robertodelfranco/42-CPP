/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:40:05 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/08/29 12:38:59 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <climits>

# define MAGENTA "\033[95m"
# define YELLOW "\033[93m"
# define GREEN "\033[92m"
# define CYAN "\033[96m"
# define RED "\033[91m"
# define NC "\033[0m"

class ClapTrap {
	protected:
		std::string	m_name;
		int			m_hitPoints;
		int			m_energy;
		int			m_attackDamage;

	public:
		ClapTrap(const std::string name);
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& other);
		~ClapTrap();
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		int		getAttackDamage();
		void	setAttackDamage(unsigned int damage);
};

#endif /* CLAPTRAP_HPP */
