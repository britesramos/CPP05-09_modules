#pragma once

#include <exception>
#include <iostream>
#include <vector>
#include <list>
#include <limits.h>
#include <unordered_map>
#include <chrono>
#include <algorithm>

#define GREEN "\033[32m"
#define RESET "\033[0m"
#define BLUE "\033[34m"
#define PINK "\033[35m"
#define YELLOW "\033[33m"
#define RED "\033[31m"

class PmergeMe
{
	private:
		unsigned int									_inputSize;
		std::vector<int>								_inputVector;
		std::list<int>									_inputList;
		std::unordered_map<int, std::pair<int, int>> 	_pairs;
		std::unordered_map<int, std::pair<int, int>>	_pairsList;
		std::vector<int> 								_main;
		std::vector<int>								_pend;
		std::vector<int>								_nonParticipating;
		std::list<int>									_mainList;
		std::list<int>									_pendList;
		std::list<int>									_nonParticipatingList;
		int												_currentJacobsthall = 3;
		int												_previousJacobsthall = 1;
		int												_timeVector;
		int 											_timeList;


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
		void insertion(unsigned int group_size);
		int calculate_nextJacobsthall();
		void insert(int index, unsigned int group_size);
		void reassembleVector();

		void fordJohnsonAlgoList();
		unsigned int firstStepList(unsigned int group_size);
		void initPairsList(unsigned int group_size);
		void ft_swapList(size_t i, unsigned int group_size);
		void nextStepsList(unsigned int group_size);
		void initializationList(unsigned int group_size);
		void insertionList(unsigned int group_size);
		void insertList(int index, unsigned int group_size);
		void reassembleList();

		void printVector(const std::string& str, const std::string& color);
		void printList(const std::string& str, const std::string& color);

		//Getters:
		const std::vector<int>& getInputVector() const;
		const std::list<int>& getInputList() const;
		int getTimeVector() const;
		int getTimeList() const;
};
