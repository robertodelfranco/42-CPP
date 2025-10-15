#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <sstream>
#include <list>
#include <stdexcept>
#include <cstdlib>

#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define RESET "\033[0m"

class RPN {
	private:
		std::list<std::string> _tokens;
		std::list<int> _results;

	public:
		RPN();
		RPN(const RPN &src);
		RPN& operator=(const RPN &src);
		~RPN();

		void    parseInput(const std::string& input);
		void    evaluate();
		int		getResult() const;
};

#endif