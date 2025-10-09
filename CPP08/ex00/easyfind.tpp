#include "easyfind.hpp"

template <typename T>

typename T::iterator	easyfind(T& container, int nb) {
	typename T::iterator it = std::find(container.begin(), container.end(), nb);

	if (it == container.end())
		throw std::runtime_error("\033[1;31mNumber was not found in the container!\033[0m");

	std::cout << GREEN << "Found: " << *it << RESET << std::endl;
	return it;
}
