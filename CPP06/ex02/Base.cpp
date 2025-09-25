#include "Base.hpp"

Base::~Base() {};

Base*	generate() {
	int r = std::rand() % 3;

	if (r == 0) {
		std::cout << GREEN << "Type C Object created!" << NC << std::endl;
		return new C;
	}
	else if (r == 1) {
		std::cout << GREEN << "Type B Object created!" << NC << std::endl;
		return new B;
	}
	else {
		std::cout << GREEN << "Type A Object created!" << NC << std::endl;
		return new A;
	}
}

void	identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "Type A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Type B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Type C" << std::endl;
	else
		std::cout << RED << "Unknown Type or Null Pointer" << NC << std::endl;
}

void	identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "Type A" << std::endl;
		return ;
	} catch (std::bad_cast&) {
		std::cout << RED << "Caught bad_cast for Type A" << NC << std::endl;
	}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "Type B" << std::endl;
		return ;
	} catch (std::bad_cast&) {
		std::cout << RED << "Caught bad_cast for Type B" << NC << std::endl;
	}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "Type C" << std::endl;
		return ;
	} catch (std::bad_cast&) {
		std::cout << RED << "Caught bad_cast for Type C" << NC << std::endl;
	}
}
