#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

#define GREEN "\033[32m"
#define WHITE "\033[1;37m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

template <typename T, typename F>

void	iter(T* array, size_t length, F func) {
	if (array == NULL || length == 0 || func == NULL) {
		return;
	}
	for (size_t i = 0; i < length; i++) {
		func(array[i]);
	}
}

#endif