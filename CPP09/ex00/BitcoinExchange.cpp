#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){
	parse_dataBase();
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
	if (std::getline(file,str))
		std::cout << "Skipped first line" << std::endl;
	while(std::getline(file, str)){
		size_t delimiter_pos = str.find(",");
		if (delimiter_pos == std::string::npos)
			throw std::runtime_error("Delimiter not found!");
		std::string key = str.substr(0, delimiter_pos);
		std::string value = str.substr(delimiter_pos + 1);
		float fvalue = stof(value);
		this->_mapData.insert({key, fvalue});
	}
}

float BitcoinExchange::bitcoin_calculations(std::string key, std::string value)
{
	float result = 0;
	float previous = 0;
	for (const auto& pair : this->_mapData){
		if (pair.first > key){
			result = stof(value) * previous;
			break ;
		}
		if (pair.first == key)
			result = stof(value) * pair.second;
		previous = pair.second;
	}
	return result;
}

bool validDate(std::string str)
{
	std::string date = str.substr(0, 10);
	if (date.length() > 10)
		return false;
	std::string year = date.substr(0, 4);
	std::string month = date.substr(5, 2);
	std::string day = date.substr(8);
	try{
		size_t posy;
		size_t posm;
		size_t posd;
		int y = std::stoi(year, &posy);
		int m = std::stoi(month, &posm);
		int d = std::stoi(day, &posd);
		if (y < 2009 || y > 2022 || posy != year.length())
			return false;
		else if (m < 0 || m > 12 || posm != month.length())
			return false;
		else if (d < 0 || d > 31 || posd != day.length())
			return false;
	}catch(const std::invalid_argument){
		return false;
	}
	return true;
}

bool validValue(std::string value)
{
	if (value.empty())
		return false;
	try {
		size_t pos;
		std::stof(value, &pos);
		if (pos != value.length())
			return false;
		return true;
	}catch(const std::invalid_argument){
		return false;
	}
	return true;
}


void BitcoinExchange::evaluate_Input(char *input){
	//1)Open file:
	std::ifstream file(input);
	if (!file.is_open())
		throw std::runtime_error("Error opening input file.");
	//2)Read file/parse:
	std::string str;
	if (std::getline(file, str))
		std::cout << "Skipped input first line" << std::endl;
	while(std::getline(file, str)){
		size_t delimiter_pos = str.find("|");
		if (delimiter_pos == std::string::npos || !validDate(str)){
			std::cout << "Error: bad input => " << str << std::endl;
		}
		else{
			std::string key = str.substr(0, delimiter_pos - 1);
			std::string value = str.substr(delimiter_pos + 2);
			if (!validValue(value))
				std::cout << "Error: invalid value." << std::endl;
			else if (stod(value) > 1000)
				std::cout << "Error: too large a number." << std::endl;
			else if (stod(value) < 0)
				std::cout << "Error: not a positive number." << std::endl;
			else {
				float res = bitcoin_calculations(key, value);
				std::cout << key << " => " << value << " = " << res << std::endl;
			}	
		}
	}
}

std::map<std::string,float> BitcoinExchange::getMapData() const{
	return this->_mapData;
}
