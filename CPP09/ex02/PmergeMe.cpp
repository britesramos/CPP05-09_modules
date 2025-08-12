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

void PmergeMe::initPairs(unsigned int j, unsigned int group_size, unsigned int dif){

	this->_pairs.clear();
	for(unsigned int i = 0; i < (this->_inputSize / group_size); ++i){
		this->_pairs.push_back({this->_inputVector[j - 1],this->_inputVector[j + group_size - dif]});
		std::cout << BLUE << "FIRST: " << this->_pairs[i].first << " ---- SECOND: " << this->_pairs[i].second << std::endl; //temp
		j += group_size;
	}
	// dif += factor;
	// factor *= 2;
	// j = group_size;
	// std::cout << PINK << "========================" << RESET << std::endl; //temp
	// initPairs(j, group_size *= 2, dif, factor);
}

void PmergeMe::ft_swap(size_t i, unsigned int group_size)
{
	std::cout << GREEN << "GROUP_SIZE: " << group_size / 2 << "\n I: " << i << std::endl;
	std::cout << GREEN << "PAIRS_FIRST: " << this->_pairs[i].first << "\nPAIRS_SECOND: " << this->_pairs[i].second << std::endl;
	for(size_t j = 0; j < group_size / 2; ++j){
		std::cout << "FIRST SWAP: " << this->_inputVector[i * group_size] << " === SECOND SWAP: " << this->_inputVector[i * group_size + 1];
		std::swap(this->_inputVector[i * group_size], this->_inputVector[i * group_size + 1]);
	}
	std::cout << YELLOW << "\nAfter ft_swap: " << RESET << std::endl;
	printVector();
}

//This should be the recursive function not the initPairs itself.
void PmergeMe::firstStep(unsigned int j, unsigned int group_size, unsigned int dif, unsigned int factor){
	if (this->_inputSize / group_size < 1)
		return ;
	initPairs(j, group_size, dif);
	dif += factor;
	factor *= 2;
	j = group_size;
	for (size_t i = 0; i < this->_pairs.size(); ++i){
		if (this->_pairs[i].first > this->_pairs[i].second)
			ft_swap(i, group_size);
	}
	std::cout << PINK << "========================" << RESET << std::endl; //temp
	firstStep(j, group_size *= 2, dif, factor);

	//compare pairs. if second is smaller swap.
}

void PmergeMe::fordJohnsonAlgo(){
	// size_t i = 0;
	// while(this->_inputSize / n > 1){
		// std::cout << i << "N: " << n << std::endl;
		firstStep(1, 2, 2, 1);
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