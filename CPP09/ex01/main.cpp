#include "RPN.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << YELLOW << "Usage: " << av[0] << " <RPN expression>" << RESET << std::endl;
		return 1;
	}

	RPN rpn;
	try {
		rpn.parseInput(av[1]);
		rpn.evaluate();
		std::cout << GREEN << rpn.getResult() << RESET << std::endl;
	} catch (const std::exception &e) {
		std::cerr << RED << e.what() << RESET << std::endl;
		return 1;
	}

	return 0;
}
