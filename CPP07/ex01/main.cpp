#include "iter.hpp"

template <typename T>
void increment(T &x) {
    x = x + 1;
}

template <typename T>
void print(const T &x) {
    std::cout << GREEN << x << " " << RESET;
}

void	test(double &x) {
	x = x + 10;
}

int main() {
	std::cout << WHITE << "-------------------------" << RESET << std::endl;
	std::cout << WHITE << "=== Testing template functions ===" << RESET << std::endl;
	std::cout << std::endl;

	int value = 42;
	print(value);
	std::cout << std::endl;
	increment(value);
	print(value);
	std::cout << std::endl;
	
	std::cout << std::endl;
	std::cout << WHITE << "-------------------------" << RESET << std::endl;
	std::cout << WHITE << "=== Testing with doubles ===" << RESET << std::endl;
	std::cout << std::endl;

	double arr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	size_t len = sizeof(arr) / sizeof(arr[0]);

	std::cout << CYAN << "Original: " << RESET;
	iter(arr, len, print<double>);
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << CYAN << "post-increment: " << RESET;
	iter(arr, len, increment<double>);
	iter(arr, len, print<double>);
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << CYAN << "test() function: " << RESET;
	iter(arr, len, test);
	iter(arr, len, print<double>);
	std::cout << std::endl;
	
	std::cout << std::endl;
	std::cout << WHITE << "-------------------------" << RESET << std::endl;
	std::cout << WHITE << "=== Testing with strings ===" << RESET << std::endl;
	std::cout << std::endl;

	std::string array[] = {
		"Hello",
		"World",
		"!",
		"20",
		"25"
	};

	len = sizeof(array) / sizeof(array[0]);

	std::cout << CYAN << "Original: " << RESET;
	iter(array, len, print<std::string>);
	std::cout << std::endl;
	std::cout << std::endl;
}
