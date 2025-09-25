#include "Base.hpp"

Base::~Base() {};

Base*	generate() {
	int r = std::rand() % 3;

	if (r == 0) {
		std::cout << "Type C Object created!" << std::endl;
		return new C;
	}
	else if (r == 1) {
		std::cout << "Type B Object created!" << std::endl;
		return new B;
	}
	else {
		std::cout << "Type A Object created!" << std::endl;
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
}

void	identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "Type A" << std::endl;
		return ;
	} catch (std::bad_cast&) {}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "Type B" << std::endl;
		return ;
	} catch (std::bad_cast&) {}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "Type C" << std::endl;
		return ;
	} catch (std::bad_cast&) {}
}
