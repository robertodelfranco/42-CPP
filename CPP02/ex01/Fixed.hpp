/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:12:15 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/08/26 14:38:09 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

# define YELLOW "\033[1;93m"
# define GREEN "\033[1;92m"
# define CYAN "\033[1;96m"
# define RED "\033[1;91m"
# define NC "\033[0m"

class Fixed {
	private:
		int	fixedValue;
		static const int fractionalBitValue;
	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream&	operator<<(std::ostream& less, const Fixed& object);

#endif /* FIXED_HPP */