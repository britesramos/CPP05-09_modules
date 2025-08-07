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
		// std::map<std::string, std::string> _mapInput;
		// std::map<std::string> _mapRespose; //Not sure about this data struct yet.


	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();


		void parse_dataBase();
		void evaluate_Input(char *input);
		float bitcoin_calculations(std::string key, std::string value);

		//Getters
		std::map<std::string, float> getMapData() const;
		// std::map<std::string, std::string> getMapInput() const;

};