#include "ScalarConverter.hpp"

int main(int argc, char *argv[]){
	if (argc == 2){
		std::string str = argv[1];
		if (str == "")
			return 1;
		ScalarConverter::convert(str);
		
	}
	else{
        std::cout << "Wrong input. Please provide a displayable character. (String literals only.)" << std::endl;
        return 1;
    }
    return 0;
}