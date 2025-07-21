#include "ScalarConverter.hpp"
#include <iomanip>
#include <cmath>
#include <climits>


static int dotCount(int strlen, std::string str)
{
	int dotCount = 0;
	for (int j = 0; j < strlen; ++j){
		if (str[j] == '.')
			dotCount++;
	}
	return dotCount;
}

static bool isChar(int strlen, std::string str)
{
	if (strlen != 1 || std::isdigit(str[0]))
		return false;
	return true;
}

static bool isInt(int strlen, std::string str)
{
	try {
		size_t i = 0;
		long long val = std::stoll(str, &i);
		if (i != static_cast<size_t>(strlen)) //To prevent stoll of throwing 'std::invalid_argument'
			return false;
		if (val < INT_MIN || val > INT_MAX)
			return false;
	} catch (...){
		return false ;
	}
	for (int i = 0; i < strlen; ++i){
		if (i == 0 && str[i] == '-')
			i = 1;
		if (std::isdigit(str[i]) == 0)
			return false;
	}
	return true;
}

static bool isFloat(int strlen, std::string str)
{
	for (int i = 0; i < strlen - 1; ++i){
		if (!std::isdigit(str[i]) && str[i] != '.' && str[i] != '-')
			return false;
	}
	if (dotCount(strlen, str) > 1)
		return false;
	if (str[strlen - 1] != 'f')
		return false;
	return true;
}
	
static bool isDouble(int strlen, std::string str)
{
	if (dotCount(strlen, str) > 1)
		return false;
	if (str.find(".") == std::string::npos)
		return false;
	return true;
}

static bool isPseudoLiteral(std::string str)
{
	if (str == "+inf" || str == "inf" || str == "-inf" || str == "nan"
			|| str == "+inff" || str == "inff" || str == "-inff" || str == "nanf")
		return true;
	return false;
}

static void printPseudoLiteral(std::string str)
{
	std::cout << "I AM A PSEUDO LITERAL" << std::endl; //temp

	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << std::stof(str) << "f" << std::endl;
	std::cout << "double: " << std::stod(str) << std::endl;
}

static void printChar(std::string str)
{
	std::cout << "I AM A CHAR!" << std::endl; //temp

	char c = str[0];
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;\
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl; //TODO: Learn about this.
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

static void printInt(std::string str)
{
	std::cout << "I AM A INT!" << std::endl; //temp

	int i = std::stoi(str);
	if (std::isprint(static_cast<char>(i)))
		std::cout << "char: " << static_cast<char>(i) << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(i) << std::endl;
	return ;
}

static void printFloat(std::string str)
{
	std::cout << "I AM A FLOAT!" << std::endl; //temp

	float f = std::stof(str);
	if (std::isprint(static_cast<char>(f)))
		std::cout << "char: " << static_cast<char>(f) << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(f) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(f) << std::endl;
	return ;
}

static void printDouble(std::string str)
{
	std::cout << "I AM A DOUBLE!" << std::endl; //temp
	double d = std::stod(str);
	if (d >= 0 && d <= 127 && std::floor(d) == d)
	{
		if (std::isprint(static_cast<char>(d)))
		std::cout << "char: " << static_cast<char>(d) << std::endl;
	}
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(d) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
	return ;
}

void ScalarConverter::convert(std::string str){

	int strlen = str.length();

	if (isPseudoLiteral(str)){
		printPseudoLiteral(str);
		return ;
	}
	else if (isChar(strlen, str)){
		printChar(str);
		return ;
	}
	else if (isInt(strlen, str)){
		printInt(str);
		return ;
	}
	else if (isFloat(strlen, str)){
		printFloat(str);
		return ;
	}
	else if (isDouble(strlen, str)){
		printDouble(str);
		return ;
	}
	else
		std::cout << "Please provide a string literal. [char, int, float or double]" << std::endl;
}