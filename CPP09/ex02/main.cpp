#include "PmergeMe.hpp"

int main(int ac, char **av) {
	if (ac < 2) {
		std::cerr << RED << "Error: Not enough arguments" << RESET << std::endl;
		return 1;
	}

	try  {
		PmergeMe pm;
		pm.init(ac, av);
	}
	catch (const std::exception &e) {
		std::cerr << RED << e.what() << RESET << std::endl;
		return 1;
	}

	return 0;
}