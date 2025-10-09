#include "easyfind.hpp"

int	main() {
	int arr[] = {1, 2, 3};
	
	std::cout << YELLOW << "Searching for 2 in vector..." << RESET << std::endl;
	std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));
	std::vector<int>::iterator	found = easyfind(vec, 2);
	std::cout << WHITEBOLD << "Value pointed by returned iterator: " << *found << RESET << std::endl;

	std::cout << YELLOW << "Searching for 3 in list..." << RESET << std::endl;
	std::list<int> lst(arr, arr + sizeof(arr) / sizeof(int));
	std::list<int>::iterator	found2 = easyfind(lst, 3);
	std::cout << WHITEBOLD << "Value pointed by returned iterator: " << *found2 << RESET << std::endl;

	std::cout << YELLOW << "Searching for 1 in deque..." << RESET << std::endl;
	std::deque<int> deq(arr, arr + sizeof(arr) / sizeof(int));
	std::deque<int>::iterator	found3 = easyfind(deq, 1);
	std::cout << WHITEBOLD << "Value pointed by returned iterator: " << *found3 << RESET << std::endl;

	try {
		std::vector<int>::iterator notFound = easyfind(vec, 4);
		std::cout << WHITEBOLD << "Value pointed by second returned iterator: " << *notFound << RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
	try {
		std::list<int>::iterator notFoundAgain = easyfind(lst, -1);
		std::cout << WHITEBOLD << "Value pointed by third returned iterator: " << *notFoundAgain << RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
	try {
		std::vector<int> emptyVec;
		std::vector<int>::iterator notFoundInEmpty = easyfind(emptyVec, 1);
		std::cout << WHITEBOLD << "Value pointed by fourth returned iterator: " << *notFoundInEmpty << RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
}
