#include "ScalarConverter.hpp"

int main(int argc, char *argv[]){
	if (argc == 2){
		std::string str = argv[1];
		// std::cout << "ARGV[1]: " << argv[1] << std::endl;
		// std::cout << str.size() << std::endl;
		//NOTE: size() will not work because 42.0f is a valid input of a float.
		ScalarConverter::convert(str);
		
	}
	else{
        std::cout << "Wrong input. Please provide a displayable character. (String literals only.)" << std::endl;
        return 1;
    }
    return 0;
}