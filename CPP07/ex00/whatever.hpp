#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define WHITE "\033[37m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

template <typename T>

void	swap(T &a, T &b) {
	T	tmp = a;
	
	a = b;
	b = tmp;
}

template <typename T>

T&	min(T &a, T &b) {
	if (a < b)
	return a;
	return b;
}

template <typename T>

T&	max(T &a, T &b) {
	if (a > b)
		return a;
	return b;
}

#endif