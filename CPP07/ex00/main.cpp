#include "whatever.hpp"

int main( void ) {
	std::cout << WHITE << "-------------------------" << RESET << std::endl;
	std::cout << WHITE << "Testing with integers" << RESET << std::endl;
	std::cout << std::endl;

	int a = 2;
	int b = 3;

	std::cout << CYAN << "a = " << a << ", b = " << b << RESET << std::endl;

	::swap( a, b );

	std::cout << CYAN << "Swapped a = " << a << ", b = " << b << RESET << std::endl;
	std::cout << CYAN << "min( a, b ) = " << ::min( a, b ) << RESET << std::endl;
	std::cout << CYAN << "max( a, b ) = " << ::max( a, b ) << RESET << std::endl;

	std::cout << std::endl;

	std::cout << WHITE << "-------------------------" << RESET << std::endl;
	std::cout << WHITE << "Testing with strings" << RESET << std::endl;

	std::cout << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	std::cout << GREEN << "c = " << c << ", d = " << d << RESET << std::endl;

	::swap(c, d);

	std::cout << GREEN << "Swapped c = " << c << ", d = " << d << RESET << std::endl;
	std::cout << GREEN << "min( c, d ) = " << ::min( c, d ) << RESET << std::endl;
	std::cout << GREEN << "max( c, d ) = " << ::max( c, d ) << RESET << std::endl;

	std::cout << std::endl;

	std::cout << WHITE << "-------------------------" << RESET << std::endl;
	std::cout << WHITE << "Testing with float values" << RESET << std::endl;

	std::cout << std::endl;

	float e = 99.5f;
	float f = 21.5f;

	std::cout << YELLOW << "e = " << e << ", f = " << f << RESET << std::endl;

	::swap(e, f);

	std::cout << YELLOW << "Swapped e = " << e << ", f = " << f << RESET << std::endl;
	std::cout << YELLOW << "min( e, f ) = " << ::min( e, f ) << RESET << std::endl;
	std::cout << YELLOW << "max( e, f ) = " << ::max( e, f ) << RESET << std::endl;

	return 0;
}