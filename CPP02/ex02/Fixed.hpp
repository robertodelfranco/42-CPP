/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 12:20:58 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/08/26 16:13:30 by rdel-fra         ###   ########.fr       */
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
		int		toInt(void) const;
		float	toFloat(void) const;

		bool	operator>(const Fixed& object)	const;
		bool	operator<(const Fixed& object)	const;
		bool	operator==(const Fixed& object)	const;
		bool	operator>=(const Fixed& object)	const;
		bool	operator<=(const Fixed& object)	const;
		bool	operator!=(const Fixed& object)	const;

		Fixed	operator+(const Fixed& object)	const;
		Fixed	operator-(const Fixed& object)	const;
		Fixed	operator*(const Fixed& object)	const;
		Fixed	operator/(const Fixed& object)	const;

		Fixed	&operator++(void);
		Fixed	operator++(int);
		Fixed	&operator--(void);
		Fixed	operator--(int);

		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream&	operator<<(std::ostream& less, const Fixed& object);

#endif /* FIXED_HPP */