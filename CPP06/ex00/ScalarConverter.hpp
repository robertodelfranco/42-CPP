#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <limits>
#include <cmath>
#include <string>
#include <cstdlib>
#include <iomanip>

enum literalTypes { CHAR, INT, FLOAT, DOUBLE, NA, INF, NEG_INF, UNKNOW };

class ScalarConverter {
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();

	static void convert(const std::string& literal);
};

#endif