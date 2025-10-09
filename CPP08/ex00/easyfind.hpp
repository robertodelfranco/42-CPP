#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <exception>
#include <algorithm>

#define WHITEBOLD "\033[1;37m"
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define RESET "\033[0m"

template <typename T>

typename T::iterator	easyfind(T& container, int nb);

#include "easyfind.tpp"

#endif