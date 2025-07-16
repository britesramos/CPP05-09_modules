#include "ScalarConverter.hpp"

int main(int argc, char *argv[]){
    std::string str = argv[1];
    std::cout << "ARGV[1]: " << argv[1] << std::endl;
    std::cout << str.size() << std::endl;
    //NOTE: size() will not work because 42.0f is a valid input of a float.
    if (argc == 2 && str.size() == 1){
        ScalarConverter::convert(str);
    }
    else{
        std::cout << "Wrong input. Please provide a displayable character." << std::endl;
        return 1;
    }
    return 0;
}