#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

static bool isDouble(const std::string& literal) {
	if (literal.empty())
		return false;
	bool has_digit = false;
	bool one = true;
	for(size_t i = 0; i < literal.length(); i++) {
		if (!std::isdigit(literal[i])) {
			if (i == 0 && (literal[i] == '+' || literal[i] == '-'))
				continue;
			if (literal[i] == '.' && one)
				one = false;
			else
				return false;
		}
		else if (!has_digit)
			has_digit = true;
	}
	if (!has_digit)
		return false;
	return true;
}

static bool isFloat(const std::string& literal) {
	if (literal.empty())
		return false;
	bool has_digit = false;
	bool one = true;
	for(size_t i = 0; i < literal.length(); i++) {
		if (literal[i] == 'f' && i + 1 == literal.length())
			break;
		if (!std::isdigit(literal[i])) {
			if (i == 0 && (literal[i] == '+' || literal[i] == '-'))
				continue;
			if (literal[i] == '.' && one)
				one = false;
			else
				return false;
		}
		else if (!has_digit)
			has_digit = true;
	}
	if (!has_digit)
		return false;
	return true;
}

static bool isInt(const std::string& literal) {
	if (literal.empty())
		return false;
	if ((literal[0] == '+' || literal[0] == '-') && literal.length() == 1)
		return false;
	for (size_t i = 0; i < literal.length(); i++) {
		if (!std::isdigit(literal[i])) {
			if (i == 0 && (literal[i] == '+' || literal[i] == '-'))
				continue;
			return false;
		}
	}
	return true;
}

static literalTypes detectLiteralType(const std::string& literal) {
	if (literal.length() == 1 && !std::isdigit(literal[0]))
		return CHAR;
	else if (isInt(literal))
		return INT;
	else if (isFloat(literal))
		return FLOAT;
	else if (isDouble(literal))
		return DOUBLE;
	else if (literal == "nan" || literal == "nanf")
		return NA;
	else if (literal == "+inf" || literal == "+inff")
		return INF;
	else if (literal == "-inf" || literal == "-inff")
		return NEG_INF;
	else
		return UNKNOW;
}

static void	printChar(double baseValue) {
	if (std::isnan(baseValue) || std::isinf(baseValue) || baseValue < 0 || baseValue > 127) {
		std::cout << "char: impossible" << std::endl;
		return ;
	}

	char c = static_cast<char>(baseValue);

	if (!std::isprint(c))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
}

static void	printInt(double baseValue) {
	if (std::isnan(baseValue) || std::isinf(baseValue) ||
		baseValue > std::numeric_limits<int>::max() || baseValue < std::numeric_limits<int>::min()) {
		std::cout << "int: impossible" << std::endl;
		return ;
	}
	std::cout << "int: " << static_cast<int>(baseValue) << std::endl;
}

static void	printFloat(double baseValue) {
	if (std::isnan(baseValue))
		std::cout << "float: nanf" << std::endl;
	else if (std::isinf(baseValue))
		std::cout << "float: " << (baseValue > 0 ? "+inff" : "-inff") << std::endl;
	else if (baseValue > std::numeric_limits<float>::max())
		std::cout << "float: +inff" << std::endl;
	else if (baseValue < -std::numeric_limits<float>::max())
		std::cout << "float: -inff" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(baseValue) << "f" << std::endl;
}

static void	printDouble(double baseValue) {
	if (std::isnan(baseValue))
		std::cout << "double: nan" << std::endl;
	else if (std::isinf(baseValue))
		std::cout << "double: " << (baseValue > 0 ? "+inf" : "-inf") << std::endl;
	else if (baseValue > std::numeric_limits<double>::max())
		std::cout << "double: +inf" << std::endl;
	else if (baseValue < -std::numeric_limits<double>::max())
		std::cout << "double: -inf" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << "double: " << baseValue << std::endl;
}

static double limitCaseInt(const std::string& literal) {
	long tmp = std::atol(literal.c_str());

	if (tmp > std::numeric_limits<int>::max())
		return INFINITY;
	if (tmp < std::numeric_limits<int>::min())
		return -INFINITY;

	return static_cast<double>(tmp);
}

void ScalarConverter::convert(const std::string& literal) {
	literalTypes	type = detectLiteralType(literal);

	double baseValue;

	try {
		switch (type) {
			case CHAR:
				baseValue = static_cast<double>(literal[0]);
				break;
			case INT:
				baseValue = limitCaseInt(literal);
				break;
			case FLOAT:
			case DOUBLE:
				baseValue = std::atof(literal.c_str());
				break;
			case NA:
				baseValue = NAN;
				break;
			case INF:
				baseValue = INFINITY;
				break;
			case NEG_INF:
				baseValue = -INFINITY;
				break;
			default:
				std::cout << "Error: Invalid Input" << std::endl;
				return;
		}
	} catch (std::out_of_range&) {
		if (!literal.empty())
			baseValue = literal[0] == '-' ? -INFINITY : INFINITY;
	}

	printChar(baseValue);
	printInt(baseValue);
	printFloat(baseValue);
	printDouble(baseValue);
}
