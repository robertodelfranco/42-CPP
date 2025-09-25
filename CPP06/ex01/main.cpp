

#include "Serializer.hpp"

int main() {
	Data data;
	data.nbr = 42;
	data.str = "Hello";
	data.str_two = "World!";

	uintptr_t	raw = Serializer::serialize(&data);

	Data*	ptr = Serializer::deserialize(raw);

	if (ptr == &data) {
		std::cout << GREEN << "The Address is the same!" << NC << std::endl;
		std::cout << std::endl;
		std::cout << GREEN << "data address: " << &data << NC << std::endl;
		std::cout << GREEN << "ptr address:  " << ptr << NC << std::endl;
		std::cout << std::endl;
		std::cout << "ptr.nbr: " << ptr->nbr << std::endl;
		std::cout << "ptr.str: " << ptr->str << std::endl;
		std::cout << "ptr.str_two: " << ptr->str_two << std::endl;
	}
	else {
		std::cout << RED << "The Address is NOT the same!" << NC << std::endl;
		std::cout << std::endl;
		std::cout << "data address: " << &data << std::endl;
		std::cout << "ptr address:  " << ptr << std::endl;
	}
}
