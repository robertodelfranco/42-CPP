#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include <stdint.h>
#include "data.hpp"

#define GREEN "\033[92m"
#define RED "\033[91m"
#define NC "\033[0m"

class Serializer {
	private:
		Serializer();
		Serializer(const Serializer& other);
		Serializer& operator=(const Serializer& other);
		~Serializer();

	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif