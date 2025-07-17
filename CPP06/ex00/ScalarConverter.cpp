#include "ScalarConverter.hpp"
#include <iomanip>

void ScalarConverter::convert(std::string str){
	//If a conversion to char is not displayable, print an informative message.
	if (str.length() == 1 && !std::isdigit(str[0])){
		char c = str[0];
		std::cout << "char: " << c << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;\
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl; //TODO: Learn about this.
		std::cout << "double: " << static_cast<double>(c) << std::endl;
		return ;
	}

	else if (str.length() == 1 && std::isdigit(str[0])){
		int i = static_cast<int>(str[0]) - 48;
		std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << static_cast<float>(i) << std::endl;
		std::cout << "double: " << static_cast<double>(i) << std::endl;
		return ;
	}

	else
		std::cout << "Non displayable character. Please provide a string literal." << std::endl;
}