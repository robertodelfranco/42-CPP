#include "Span.hpp"

Span::Span() : m_n(0), m_vec() {
	std::cout << WHITEBOLD << "Span default constructor called" << RESET << std::endl;
}

Span::Span(unsigned int n) : m_n(n), m_vec() {
	m_vec.reserve(n);
	std::cout << GREEN << "Span parameterized constructor called" << RESET << std::endl;
}

Span::Span(const Span& other) : m_n(other.m_n), m_vec(other.m_vec) {
	std::cout << CYAN << "Span copy constructor called" << RESET << std::endl;
}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		m_n = other.m_n;
		m_vec = other.m_vec;
		std::cout << YELLOW << "Span assignment operator called" << RESET << std::endl;
	}
	return *this;
}

Span::~Span() {
	std::cout << RED << "Span destructor called" << RESET << std::endl;
}

void	Span::addNumber(int n) {
	if (m_vec.size() >= m_n) {
		throw SpanFullException();
	}
	m_vec.push_back(n);
}

long	Span::shortestSpan() const {
	if (m_vec.size() < 2) {
		throw NotEnoughNumbersException();
	}

	std::vector<int> tempVec = m_vec;

	std::sort(tempVec.begin(), tempVec.end());
	
	long	minSpan = LONG_MAX;
	
	for (size_t i = 1; i < tempVec.size(); ++i) {
		long span = static_cast<long>(tempVec[i]) - static_cast<long>(tempVec[i - 1]);
		if (span < minSpan) {
			minSpan = span;
		}
	}
	return minSpan;
}

long	Span::longestSpan() const {
	if (m_vec.size() < 2) {
		throw NotEnoughNumbersException();
	}

	std::vector<int> tempVec = m_vec;

	std::sort(tempVec.begin(), tempVec.end());

	long result = static_cast<long>(tempVec.back()) - static_cast<long>(tempVec.front());

	return result;
}

const char* Span::SpanFullException::what() const throw() {
	return "Span is full, cannot add more numbers";
}

const char* Span::NotEnoughNumbersException::what() const throw() {
	return "Not enough numbers to find a span";
}

const char* Span::InvalidRangeException::what() const throw() {
	return "Invalid range: end iterator is before start iterator";
}

void	Span::addNumberRange(std::vector<int>::iterator start, std::vector<int>::iterator end) {
	std::vector<int>::difference_type diff = std::distance(start, end);

	if (diff < 0) {
		throw InvalidRangeException();
	}
	
	size_t rangeSize = static_cast<size_t>(diff);

	size_t capacityLeft = m_n - m_vec.size();

	if (rangeSize > capacityLeft) {
		throw SpanFullException();
	}

	std::vector<int> newElements(start, end);
	m_vec.insert(m_vec.end(), newElements.begin(), newElements.end());
}
