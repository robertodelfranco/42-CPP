/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 19:11:44 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/08/27 14:01:10 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed	crossProduct(Point const &u, Point const &v, Point const &w) {
	Fixed x1 = v.getX() - u.getX();
	Fixed y1 = v.getY() - u.getY();
	Fixed x2 = w.getX() - u.getX();
	Fixed y2 = w.getY() - u.getY();

	return x1 * y2 - y1 * x2;
}

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed	cp1 = crossProduct(a, b, point);
	Fixed	cp2 = crossProduct(b, c, point);
	Fixed	cp3 = crossProduct(c, a, point);

	std::cout << YELLOW << "CP1= " << cp1 << " CP2= " << cp2 << " CP3= " << cp3 << NC << std::endl;
	if (cp1 == Fixed(0) || cp2 == Fixed(0) || cp3 == Fixed(0))
		return false;

	bool allPositive = (cp1 > Fixed(0) && cp2 > Fixed(0) && cp3 > Fixed(0));
	bool allNegative = (cp1 < Fixed(0) && cp2 < Fixed(0) && cp3 < Fixed(0));

	return (allPositive || allNegative);
}
