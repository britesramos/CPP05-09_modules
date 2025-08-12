#pragma once

#include <exception>
#include <iostream>
#include <vector>
#include <list>
#include <limits.h>

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
		std::vector<std::pair<int, int>> _pairs;
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
		void firstStep(unsigned int j, unsigned int group_size, unsigned int dif, unsigned int factor);
		void initPairs(unsigned int start, unsigned int group_size, unsigned int dif);
		void ft_swap(size_t i, unsigned int group_size);

		void printVector();

		//GETTERs:
		std::vector<int> getInputVector();
};
