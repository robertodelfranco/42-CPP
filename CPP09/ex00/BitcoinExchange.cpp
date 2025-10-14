#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _data() {
	std::cout << GREEN << "BitcoinExchange default constructor called" << RESET << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _data(other._data) {
	std::cout << CYAN << "BitcoinExchange copy constructor called" << RESET << std::endl;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	std::cout << YELLOW << "BitcoinExchange copy assignment operator called" << RESET << std::endl;
	if (this != &other) {
		_data = other._data;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {
	std::cout << MAGENTA << "BitcoinExchange destructor called" << RESET << std::endl;
}

static int	daysInMonth(int	month, int year) {
	if (month == 2) {
		if (year == 2012 || year == 2016 || year == 2020)
			return 29;
		return 28;
	}

	if (month == 4 || month == 6 || month == 9 || month == 11)
		return 30;

	return 31;
}

static bool	isDateValid(const std::string& key) {
	if (key.length() != 10)
		return false;
	
	for (size_t i = 0; i < key.length(); i++) {
		if (!isdigit(key[i])) {
			if ((i == 4 || i == 7) && key[i] == '-')
				continue ;
			return false;
		}
	}

	int year = std::atoi(key.substr(0, 4).c_str());
	int	month = std::atoi(key.substr(5, 2).c_str());
	int	day = std::atoi(key.substr(8, 2).c_str());

	if (year >= 2009)
		if (month >= 1 && month <= 12)
			if (day >= 1 && day <= daysInMonth(month, year))
				return true;
	return false;
}

static bool	isValueValid(const std::string& str) {
	long	value = std::atol(str.c_str());

	if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min()) {
		std::cout << RED << "Error: number out of range" << RESET << std::endl;
		return false;
	}

	if (value < 0) {
		std::cout << RED << "Error: not a positive number" << RESET << std::endl;
		return false;
	}

	return true;
}

void	BitcoinExchange::processLine(const std::string& key, const std::string& value) {
	if (!isDateValid(key)) {
		std::cout << RED << "Error: bad input date => " << key << RESET << std::endl;
		return ;
	}

	if (!isValueValid(value))
		return ;
	
	std::map<std::string, float>::iterator it = _data.find(key);

	if (it == _data.end()) {
		std::map<std::string, float>::iterator it2 = _data.lower_bound(key);

		if (it2 == _data.begin()) {
			std::cout << RED << "Error: no earlier date available for " << key << RESET << std::endl;
			return ;
		}
		--it2;
		it = it2;
	}
	std::cout << WHITEBOLD << it->first << " => " << value << " = " << (std::atof(value.c_str()) * it->second) << RESET << std::endl;
}

static	std::string	trim(const std::string& str) {
	size_t	first = str.find_first_not_of(" \t\n\f\v");
	
	if (first == std::string::npos)
		return std::string();
	
	size_t	last = str.find_last_not_of(" \t\n\f\v");

	return str.substr(first, last - first + 1);
}

void	BitcoinExchange::loadFile(const std::string& filename) {
	if (filename.empty()) {
		std::cerr << RED << "Error: could not open input file" << RESET << std::endl;
	}

	std::ifstream infile(filename.c_str());

	if (!infile) {
		std::cerr << RED << "Error to open input file" << RESET << std::endl;
	}

	std::string line;
	std::getline(infile, line);
	while (std::getline(infile, line)) {
		if (line.empty())
			continue ;

		size_t	find = line.find("|");

		if (find == std::string::npos) {
			std::cout << RED << "Error: Bad input => " << line << RESET << std::endl;
			continue ;
		}

		std::string key = trim(line.substr(0, find));
		std::string value = trim(line.substr(find + 1));
		if (key.empty() || value.empty()) {
			std::cout << RED << "Error: Bad input => " << key << " " << value << RESET << std::endl;
		}

		processLine(key, value);
	}
}

void	BitcoinExchange::loadData() {
	std::ifstream infile("data.csv");

	if (!infile) {
		std::cerr << RED << "Error to open data file" << RESET << std::endl;
	}

	std::string line;
	while (std::getline(infile, line)) {
		if (line.empty())
			continue ;
		
		size_t	find = line.find(",");

		if (find == std::string::npos)
			continue ;
		
		std::string key = trim(line.substr(0, find));
		std::string value = trim(line.substr(find + 1));

		_data.insert(std::make_pair(key, std::atof(value.c_str())));
	}
}


void	BitcoinExchange::startProcess(const std::string& filename) {
	loadData();
	loadFile(filename);
}


