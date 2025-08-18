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

void PmergeMe::initPairs(unsigned int group_size){

	unsigned int j = 1;
	this->_pairs.clear();
	for(unsigned int i = 0; i < (this->_inputSize / (group_size * 2)); ++i){
		this->_pairs.insert({(group_size * j) - 1, {this->_inputVector[(group_size * j) - 1],this->_inputVector[(group_size * (j + 1)) - 1]}});
		// auto [a, b] = this->_pairs[(group_size * j) - 1]; //temp
		// std::cout << BLUE << "A)INDEX: " << (group_size * j) - 1 <<  "  FIRST: " << a << " ---- SECOND: " << b << std::endl; //temp
		j += 2;
	}
}

void PmergeMe::ft_swap(size_t i, unsigned int group_size)
{
	std::cout << BLUE << "GROUP_SIZE: " << group_size;
	std::cout << YELLOW << " | PAIRS_FIRST: " << this->_pairs[i].first << " ==== PAIRS_SECOND: " << this->_pairs[i].second << std::endl;
	for(size_t j = 0; j < group_size; ++j){
		std::cout << GREEN << "==> FIRST SWAP: " << this->_inputVector[i - j] << " === SECOND SWAP: " << this->_inputVector[i + group_size - j] << std::endl;
		std::swap(this->_inputVector[i - j], this->_inputVector[i + group_size - j]);
	}
	std::cout << YELLOW << "\nAfter ft_swap: " << RESET << std::endl; //temp
	printVector(); //temp
	std::cout << PINK << "========================" << RESET << std::endl; //temp
}

void PmergeMe::firstStep(unsigned int group_size){
	if (this->_inputSize / group_size < 1)
		return ;
	initPairs(group_size);
	for (const auto& [key, value] : this->_pairs){
		auto [a, b] = this->_pairs[key];
		if (a > b)
			ft_swap(key, group_size);
	}
	firstStep(group_size *= 2);
}

void PmergeMe::fordJohnsonAlgo(){
		firstStep(1);
		//NextSteps;
}

void PmergeMe::printVector(){
	for(size_t i = 0; i < this->_inputVector.size(); ++i){
		std::cout << PINK << "Vector[" << i << "]: " << this->_inputVector[i] << RESET << std::endl;
	}
}

std::vector<int> PmergeMe::getInputVector(){
	return this->_inputVector;
}