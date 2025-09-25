#include "Base.hpp"
#include <ctime>

int main() {
	std::srand(std::time(NULL));

	Base* obj1 = generate();

	identify(obj1);
	identify(*obj1);

	std::cout << "----------------" << std::endl;
	
	Base* obj2 = generate();
	
	identify(obj2);
	identify(*obj2);
	
	std::cout << "----------------" << std::endl;
	
	Base* obj3 = generate();
	
	identify(obj3);
	identify(*obj3);
	
	std::cout << "----------------" << std::endl;

	Base* obj4 = generate();
	
	identify(obj4);
	identify(*obj4);

	std::cout << "----------------" << std::endl;

	Base* p = NULL;

	identify(p);

	delete obj1;
	delete obj2;
	delete obj3;
	delete obj4;
}
