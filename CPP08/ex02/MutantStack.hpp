#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>
#include <list>

#define WHITEBOLD "\033[1;37m"
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define CYAN "\033[1;36m"
#define RED "\033[1;31m"
#define RESET "\033[0m"

template <typename T>

class MutantStack : public std::stack<T> {
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		MutantStack() : std::stack<T>() {
			std::cout << GREEN << "MutantStack default constructor called" << RESET << std::endl;
		};
		
		MutantStack(const MutantStack& other) : std::stack<T>(other) {
			std::cout << CYAN << "MutantStack copy constructor called" << RESET << std::endl;
		};
		
		MutantStack& operator=(const MutantStack& other) {
			std::cout << YELLOW << "MutantStack assignment operator called" << RESET << std::endl;
			if (this != &other) {
				std::stack<T>::operator=(other);
			}
			return *this;
		}
		
		~MutantStack() {
			std::cout << RED << "MutantStack destructor called" << RESET << std::endl;
		};

		iterator begin() {
			return this->c.begin();
		};

		iterator end() {
			return this->c.end();
		};

		const_iterator begin() const {
			return this->c.begin();
		};

		const_iterator end() const {
			return this->c.end();
		};

		reverse_iterator rbegin() {
			return this->c.rbegin();
		};

		reverse_iterator rend() {
			return this->c.rend();
		};

		const_reverse_iterator rbegin() const {
			return this->c.rbegin();
		};

		const_reverse_iterator rend() const {
			return this->c.rend();
		};
};

#endif