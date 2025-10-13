#include "Span.hpp"

int main() {
	Span sp = Span(7);
	std::cout << std::endl;
	
	try {
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
		std::cout << std::endl;
		
		std::vector<int> numbers;
		for (int i = 0; i < 10; ++i) {
			numbers.push_back(i * 10);
		}

		Span span = Span(10);
		Span sp2 = span;
		std::cout << std::endl;

		sp2.addNumberRange(numbers.begin(), numbers.end());

		std::cout << "Shortest Span in sp2: " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest Span in sp2: " << sp2.longestSpan() << std::endl;
		std::cout << std::endl;
	} catch (const std::exception& e) {
		std::cerr << WHITEBOLD << "Exception: " << e.what() << RESET << std::endl;
	}

	Span s(sp);
	std::cout << std::endl;

    s.addNumber(INT_MIN);
    s.addNumber(INT_MAX);

    long longest = s.longestSpan();
    long shortest = s.shortestSpan();

	std::cout << "Shortest span still " << shortest << std::endl;
	std::cout << std::endl;


	std::cout << "Longest span between INT_MIN and INT_MAX:  " << longest << std::endl;
	std::cout << "Expected span between INT_MIN and INT_MAX: " << static_cast<long>(INT_MAX) - static_cast<long>(INT_MIN) << std::endl;
	std::cout << std::endl;

	try {
		Span s_invalid(5);
		std::vector<int> vec;
		for (int i = 0; i < 5; ++i) {
			vec.push_back(i);
		}
		s_invalid.addNumberRange(vec.end(), vec.begin());
	} catch (const std::exception& e) {
		std::cerr << WHITEBOLD << "Exception: " << e.what() << RESET << std::endl;
	}

	Span range(100000);
	std::vector<int> largeVec;

	for (int i = 0; i < 100000; ++i) {
		largeVec.push_back(i * 3);
	}
	
	range.addNumberRange(largeVec.begin(), largeVec.end());

	// Test shortest and longest span
	std::cout << "Shortest Span in largeVec: " << range.shortestSpan() << std::endl;
	std::cout << "Longest Span in largeVec: " << range.longestSpan() << std::endl;
	std::cout << std::endl;

	return 0;
}
