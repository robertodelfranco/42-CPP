#include "easyfind.hpp"

template <typename T>

void	easyfind(T* container, int nb) {
	if (container == NULL) {
		std::cout << RED << "Null Pointer!" << RESET << std::endl;
		return ;
	}

	for (int i = 0; i < container.size(); i++) {
		if (container[i] == nb) {
			std::cout << GREEN << "Number " << nb << " was found in the " << i << " position of the container." << RESET << std::endl;
			return ;
		}
	}
	throw std::("Nb was not found!");
}
