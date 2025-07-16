#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string str){
	//If a conversion to char is not displayable, print an informative message.
	if (std::isprint(static_cast<unsigned char>(str[0]))){
		std::cout << "YEAH!" << std::endl;
	}
}