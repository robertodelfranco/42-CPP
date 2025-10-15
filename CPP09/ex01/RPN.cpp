#include "RPN.hpp"

RPN::RPN() : _tokens(), _results() {}

RPN::RPN(const RPN &src) : _tokens(src._tokens), _results(src._results) {}

RPN& RPN::operator=(const RPN &src) {
	if (this != &src) {
		_tokens = src._tokens;
		_results = src._results;
	}
	return *this;
}

RPN::~RPN() {}

void RPN::parseInput(const std::string &input) {
	std::istringstream iss(input);
	std::string token;

	_tokens.clear();
	_results.clear();

	while (iss >> token) {
		_tokens.push_back(token);
	}

	if (_tokens.empty())
		throw std::runtime_error("Error: Empty input");
}

void RPN::evaluate() {
	for (std::list<std::string>::const_iterator it = _tokens.begin(); it != _tokens.end(); ++it) {
		const std::string& token = *it;

		if (token == "+" || token == "-" || token == "/" || token == "*")
			if (_results.size() < 2)
				throw std::runtime_error("Error: Not enough operands for operation");
		
		if (token == "+") {
			int b = _results.back(); _results.pop_back();
			int a = _results.back(); _results.pop_back();
			_results.push_back(a + b);
		}
		else if (token == "-") {
			int b = _results.back(); _results.pop_back();
			int a = _results.back(); _results.pop_back();
			_results.push_back(a - b);
		}
		else if (token == "*") {
			int b = _results.back(); _results.pop_back();
			int a = _results.back(); _results.pop_back();
			_results.push_back(a * b);
		}
		else if (token == "/") {
			int b = _results.back(); _results.pop_back();
			if (b == 0)
				throw std::runtime_error("Error: Division by zero");
			int a = _results.back(); _results.pop_back();
			_results.push_back(a / b);
		}
		else {
			if (token.length() != 1 || !std::isdigit(static_cast<unsigned char>(token[0])))
				throw std::runtime_error("Error: Invalid token '" + token + "'");
			int value = std::atoi(token.c_str());
			_results.push_back(value);
		}
	}
	if (_results.size() != 1)
		throw std::runtime_error("Error: No result available");
}

int	RPN::getResult() const {
	return _results.back();
}
