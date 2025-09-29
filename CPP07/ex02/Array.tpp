#include "Array.hpp"

template <typename T>
Array<T>::Array() : m_array(NULL), m_nb(0) {
	std::cout << GREEN << "Array Default constructor called" << RESET << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : m_array(new T[n]()), m_nb(n) {
	std::cout << CYAN << "Array parameterized constructor called" << RESET << std::endl;
}

template <typename T>
Array<T>::Array(const Array& other) : m_array(new T[other.m_nb]), m_nb(other.m_nb) {
	std::cout << YELLOW << "Array copy constructor called" << RESET << std::endl;
	for (size_t i = 0; i < m_nb; i++)
		m_array[i] = other.m_array[i];
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array& other) {
	std::cout << MAGENTA << "Array copy assignment constructor called" << RESET << std::endl;
	if (this != &other) {
		delete[] m_array;
		m_nb = other.m_nb;
		m_array = new T[m_nb];
		for (size_t i = 0; i < m_nb; i++)
			m_array[i] = other.m_array[i];
	}
	return *this;
}

template <typename T>
Array<T>::~Array() {
	std::cout << RED << "Array Destructor called" << RESET << std::endl;
	delete[] m_array;
}

template <typename T>
unsigned int	Array<T>::size() const {
	return m_nb;
}

template <typename T>
T&	Array<T>::operator[](unsigned int i) {
	if (i >= m_nb)
		throw std::out_of_range("Index out of range");
	return m_array[i];
}
