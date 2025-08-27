/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:50:23 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/08/26 19:48:31 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
	private:
		Fixed const x;
		Fixed const y;

	public:
		Point();
		Point(const float f_x, const float f_y);
		Point(const Point& other);
		Point& operator=(const Point& other);
		~Point();
		Fixed	getX() const;
		Fixed	getY() const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif /* POINT_HPP */