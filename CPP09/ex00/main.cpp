#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		try{
			BitcoinExchange bit(argv[1]);
			//Iterate over map and collect information in another map.
			//Output map response.
		}catch(std::exception &e){
			std::cerr << RED << "Exception: " << e.what() << std::endl;
		}
	}
	else
	{
		std::cout << RED << "Please provide a correct input: 'program's name' + [input file].txt" << RESET << std::endl;
		return (1);
	}
	return 0;
}