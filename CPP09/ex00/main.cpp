#include <iostream>
#include <iomanip>
#include "BitcoinExchange.hpp"

void printMap(std::map<std::string, std::string> map) //temp
{
	for (const auto& pair : map)
		std::cout << pair.first << " => " << std::setprecision(7) << pair.second << std::endl;
}

template <typename T, typename T1> //temp
void outputIntoFile(std::map<T, T1> map, std::string fileName)
{
	std::ofstream outFile(fileName);
	if (!outFile)
		throw std::runtime_error ("Failed open outFile.");
	for (const auto& pair : map)
		outFile << pair.first << " => " << std::setprecision(7) << pair.second << std::endl;

}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		try{
			BitcoinExchange bit;
			bit.evaluate_Input(argv[1]);
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