#include "whatever.hpp"

int main( void ) {
	int a = 2;
	int b = 3;

	std::cout << "a = " << a << ", b = " << b << std::endl;

	::swap( a, b );

	std::cout << "Swapped a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::cout << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	std::cout << "c = " << c << ", d = " << d << std::endl;

	::swap(c, d);

	std::cout << "Swapped c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	std::cout << std::endl;
	std::cout << "-----------------------------------" << std::endl;

	std::cout << "Testing with float values" << std::endl;
	std::cout << std::endl;

	float e = 99.5f;
	float f = 21.5f;

	std::cout << "e = " << e << ", f = " << f << std::endl;

	::swap(e, f);

	std::cout << "Swapped e = " << e << ", f = " << f << std::endl;
	std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
	std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;

	return 0;
}