#pragma once

#include <map>
#include <string>
#include <iostream>
#include <fstream>

#define GREEN "\033[32m"
#define RESET "\033[0m"
#define BLUE "\033[34m"
#define PINK "\033[35m"
#define YELLOW "\033[33m"
#define RED "\033[31m"

class BitcoinExchange
{
	private:
		std::map<std::string, float> _mapData;
		std::map<std::string, float> _mapInput;
		// std::map<std::string> _mapRespose; //Not sure about this data struct yet.


	public:
		BitcoinExchange(char *input);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();


		void parse_dataBase();
		// void parse_Input(char *input);
		// void bitcoin_calculations();
};