#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(char *input){
	(void)input; //temp
	parse_dataBase();
	// parse_Input(input); //TODO
	std::cout << YELLOW << "BitcoinExchange default constructor called." << RESET << std::endl;
}

BitcoinExchange::~BitcoinExchange(){
	std::cout << YELLOW << "BitcoinExchange default desconstructor called." << RESET << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other){
	std::cout << YELLOW << "BitcoinExchange copy constructor called." << RESET << std::endl;
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other){
	std::cout << YELLOW << "BitcoinExchange copy assignment operator called." << RESET << std::endl;
	if (this != &other){
		this->_mapData = other._mapData;
		this->_mapInput = other._mapInput;
	}
	return *this;
}

void BitcoinExchange::parse_dataBase(){
	//1)Open file:
	std::ifstream file("data.csv");
	if (!file.is_open())
		throw std::runtime_error("Error opening data.csv");
	//2)Read file/parse:
	std::string str;
	while(std::getline(file, str)){
		size_t delimiter_pos = str.find(",") + 1;
		if (delimiter_pos == std::string::npos)
			throw std::runtime_error("Delimiter not found!");
		std::string key = str.substr(0, delimiter_pos);
		std::string value = str.substr(delimiter_pos + 1);
		float fvalue = stof(value);
		this->_mapData.insert({key, fvalue});
	}
}

// void BitcoinExchange::parse_Input(char *input){
// 	//1)Open file:
// 	//2)Read file/parse:
// }