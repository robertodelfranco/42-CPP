#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <climits>

#define WHITEBOLD "\033[1;37m"
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define CYAN "\033[1;36m"
#define RED "\033[1;31m"
#define RESET "\033[0m"

class Span {
	private:
		unsigned int		m_n;
		std::vector<int>	m_vec;

	public:
		Span();
		Span(unsigned int n);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void	addNumber(int n);
		long	shortestSpan() const;
		long	longestSpan() const;

		class SpanFullException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class NotEnoughNumbersException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class InvalidRangeException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		void	addNumberRange(std::vector<int>::iterator start, std::vector<int>::iterator end);
};

#endif