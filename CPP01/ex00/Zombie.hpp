/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 21:37:39 by marvin            #+#    #+#             */
/*   Updated: 2025/08/23 21:37:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie {
	private:
		std::string _name;

	public:
		void announce( void );
		Zombie(std::string name);
		~Zombie();
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif /* ZOMBIE_HPP */
