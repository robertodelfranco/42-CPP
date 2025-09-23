#include "Base.hpp"
#include <ctime>

int main() {
	std::srand(std::time(NULL));

	Base* obj1 = generate();
	
	identify(obj1);
	identify(*obj1);

	Base* obj2 = generate();
	
	identify(obj2);
	identify(*obj2);

	Base* obj3 = generate();
	
	identify(obj3);
	identify(*obj3);

	Base* obj4 = generate();
	
	identify(obj4);
	identify(*obj4);

	delete obj1;
	delete obj2;
	delete obj3;
	delete obj4;
}
