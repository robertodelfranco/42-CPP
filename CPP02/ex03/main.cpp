/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 14:39:22 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/08/27 14:52:11 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main() {
	{
		Point	a(0, 0);
		Point	b(4, 0);
		Point   c(0, 3);
	
		Point	inside(1, 1);
		Point	outside(5, 1);
		Point	edge(2, 0);

		std::cout << CYAN << "0 means outside/vertex/edge and 1 inside" << NC << std::endl;
		std::cout << std::endl;
		bool	in = bsp(a, b, c, inside);
		std::cout << "Inside?  " << in << std::endl;
		std::cout << std::endl;
		bool	out = bsp(a, b, c, outside);
		std::cout << "Outside? " << out << std::endl;
		std::cout << std::endl;
		bool	ed = bsp(a, b, c, edge);
		std::cout << "Edge? " << ed << std::endl;
		std::cout << std::endl;
	}
	{
		Point   a(-2, -1);
		Point   b(3, -2);
		Point   c(0, 4);
		
		Point	P1(0, 0);
		Point	P2(3, 2);
		Point	P3(-1, 3);
		Point	P4(0, 4);
		
		bool	in = bsp(a, b, c, P1);
		std::cout << "Inside?  " << in << std::endl;
		std::cout << std::endl;
		bool	out = bsp(a, b, c, P2);
		std::cout << "Outside? " << out << std::endl;
		std::cout << std::endl;
		bool	outside = bsp(a, b, c, P3);
		std::cout << "Outside? " << outside << std::endl;
		std::cout << std::endl;
		bool	vertex = bsp(a, b, c, P4);
		std::cout << "Vertex? " << vertex << std::endl;
	}	
	return 0;
}
