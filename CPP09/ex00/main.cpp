#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Usage: ./btc <input_file>" << std::endl;
		return 1;
	}

	BitcoinExchange exchange;
	std::cout << std::endl;
	
	exchange.startProcess(av[1]);
	
	std::cout << std::endl;
	return 0;
}
