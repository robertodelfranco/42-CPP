#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <exception>

#define GREEN "\033[1;33m"
#define RED "\033[1;31m"
#define RESET "\033[0m"

template <typename T>

void	easyfind(T* container, int nb);

#include "easyfind.tpp"

#endif