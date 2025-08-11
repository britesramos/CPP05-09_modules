#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **argv){
	std::cout << YELLOW << "PmergeMe constructor called." << RESET << std::endl;
	parseInput(argv);
}

PmergeMe::PmergeMe(const PmergeMe& other){
	*this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other){
	if (this != &other){
		this->_inputVector = other._inputVector;
		this->_inputSize = other._inputSize;
		// this->_inputList = other._inputList;
	}
	return *this;
}


PmergeMe::~PmergeMe(){
	std::cout << YELLOW << "PmergeMe destructor called." << RESET << std::endl;
}

bool PmergeMe::isDigit(char *argv){
	size_t i = 0;
	while(argv[i]){
		if (!(argv[i] >= '0' && argv[i] <= '9'))
			return false;
		i++;
	}
	return true;
}

bool PmergeMe::isInt(char *argv){
	long l = atol(argv);
	// std::cout << "LONG: " << l << std::endl; //temp
	if (l > INT_MAX)
		return false;
	return true;
}

bool PmergeMe::isValidInput(char *argv){
	if (!isDigit(argv)){
		throw std::runtime_error("Not valid integer.");
		return false;
	}
	else if(!isInt(argv)){
		throw std::runtime_error("Exceed integer limits.");
		return false;
	}	
	return true;
}

void PmergeMe::parseInput(char **argv){
	size_t i = 1;
	while(argv[i]){
		// std::cout << BLUE << "ARGV: " << argv[i] << RESET << std::endl;
		if (isValidInput(argv[i]))
			this->_inputVector.push_back(std::atoi(argv[i]));
		i++;
	}
	this->_inputSize = this->_inputVector.size();
	// printVector(); //temp
}

void PmergeMe::initPairs(unsigned int j, unsigned int n){
	// unsigned int j = 1;
	// std::cout << PINK << this->_inputSize / n << std::endl;
	if (this->_inputSize / n < 1)
		return ;
	this->_pairs.clear();
	for(unsigned int i = 0; i < (this->_inputSize / n); ++i){
		std::cout << "J: " << j << " ==== N: " << n << std::endl;
		// std::cout << YELLOW << "J - 1: " << j - 1 << " -> J + N - 2: " << j + n - 2 << std::endl; 
		this->_pairs.push_back({this->_inputVector[j - 1],this->_inputVector[j + n - 2]});
		std::cout << BLUE << "FIRST: " << this->_pairs[i].first << " ---- SECOND: " << this->_pairs[i].second << std::endl;
		j += n;
	}
	j = n;
	std::cout << PINK << "========================" << RESET << std::endl;
	initPairs(j, n *= 2);
}

//This should be the recursive function not the initPairs itself.
void PmergeMe::firstStep(){
	initPairs(1, 2);
	//pairs of n elements.
	//if cant make 2 pairs of n elements recursion is over.
	//compare pairs. if second is smaller swap.
}

void PmergeMe::fordJohnsonAlgo(){
	// size_t i = 0;
	// while(this->_inputSize / n > 1){
		// std::cout << i << "N: " << n << std::endl;
		firstStep();
	// 	i++;
	// 	n *= 2;
	// }
}

void PmergeMe::printVector(){
	for(size_t i = 0; i < this->_inputVector.size(); ++i){
		std::cout << PINK << "Vector[" << i << "]: " << this->_inputVector[i] << RESET << std::endl;
	}
}

std::vector<int> PmergeMe::getInputVector(){
	return this->_inputVector;
}