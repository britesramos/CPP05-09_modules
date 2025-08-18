#pragma once

#include <exception>
#include <iostream>
#include <vector>
#include <list>
#include <limits.h>
#include <unordered_map>

#define GREEN "\033[32m"
#define RESET "\033[0m"
#define BLUE "\033[34m"
#define PINK "\033[35m"
#define YELLOW "\033[33m"
#define RED "\033[31m"

class PmergeMe
{
	private:
		unsigned int	_inputSize;
		std::vector<int> _inputVector;
		std::unordered_map<int, std::pair<int, int>> _pairs;
		std::vector<int> _main;
		std::vector<int> _pend;
		// std::list<int> _inputList;
		// int _timeVector;
		// int _timeList;

	public:
		PmergeMe(char **argv);
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void parseInput(char **argv);
		bool isValidInput(char *argv);
		bool isDigit(char *argv);
		bool isInt(char *argv);

		void fordJohnsonAlgo();
		unsigned int firstStep(unsigned int group_size);
		void initPairs(unsigned int group_size);
		void ft_swap(size_t i, unsigned int group_size);
		void nextSteps(unsigned int group_size);
		void initialization(unsigned int group_size);
		// void insertion(unsigned int group_size); //TODO

		void printVector(std::string str, std::vector<int> vector);

		//GETTERs:
		std::vector<int> getInputVector();
};
