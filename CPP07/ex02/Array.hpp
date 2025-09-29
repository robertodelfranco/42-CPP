#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <exception>

#define MAGENTA "\033[35m"
#define YELLOW "\033[33m"
#define WHITE "\033[1;37m"
#define GREEN "\033[32m"
#define CYAN "\033[36m"
#define RED "\033[31m"
#define RESET "\033[0m"

template <typename T>

class Array {
	private:
		T*				m_array;
		unsigned int	m_nb;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		Array<T>& operator=(const Array& other);
		~Array();

		unsigned int	size() const;
		T& operator[](unsigned int i);
};

#include "Array.tpp"

#endif