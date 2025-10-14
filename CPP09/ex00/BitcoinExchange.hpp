#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <limits>
#include <cstdlib>
#include <string>
#include <fstream>
#include <map>

#define WHITEBOLD "\033[1;37m"
#define MAGENTA "\033[1;35m"
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define CYAN "\033[1;36m"
#define RED "\033[1;31m"
#define RESET "\033[0m"

class BitcoinExchange {
	private:
		std::map<std::string, float>	_data;

		void	loadData();
		void	loadFile(const std::string& filename);
		void	processLine(const std::string& key, const std::string& value);

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		void	startProcess(const std::string& filename);
};

#endif