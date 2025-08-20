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
	printVector("Vector[", this->_inputVector); //temp
	std::cout << PINK << "========================" << RESET << std::endl; //temp
}

unsigned int PmergeMe::firstStep(unsigned int group_size){
	if (this->_inputSize / group_size < 1)
		return (group_size);
	initPairs(group_size);
	for (const auto& [key, value] : this->_pairs){
		auto [a, b] = this->_pairs[key];
		if (a > b)
			ft_swap(key, group_size);
	}
	firstStep(group_size *= 2);
	return group_size;
}

void PmergeMe::initialization(unsigned int group_size)
{
	this->_main.clear();
	this->_pend.clear();
	this->_nonParticipating.clear();
	for(size_t j = 0; j < (group_size * 2); ++j){
		this->_main.push_back(this->_inputVector[j]);
	}
	size_t i = group_size * 2;
	while(i < this->_inputVector.size()){
		if ((i + group_size) > this->_inputVector.size()){
			while(i < this->_inputVector.size()){
				this->_nonParticipating.push_back(this->_inputVector[i]);
				i++;
			}
			break ;
		}
		else{
			for(size_t a = 0; a < group_size && i < this->_inputVector.size(); ++a){
				this->_pend.push_back(this->_inputVector[i]);
				i++;
			}
			if (!((i + group_size) > this->_inputVector.size())){
				for(size_t a = 0; a < group_size && i < this->_inputVector.size(); ++a){
					this->_main.push_back(this->_inputVector[i]);
					i++;
				}
			}
		}
	}
	printVector("VECTOR[", this->_inputVector); //temp
	printVector("Main[", this->_main); //temp
	printVector("Pend[", this->_pend); //temp
	printVector("NonParticipating[", this->_nonParticipating); //temp
}

void PmergeMe::reassembleVector()
{
	this->_inputVector.clear();
	this->_inputVector.insert(this->_inputVector.end(), this->_main.begin(), this->_main.end());
	if (!this->_nonParticipating.empty())
		this->_inputVector.insert(this->_inputVector.end(), this->_nonParticipating.begin(), this->_nonParticipating.end());
}

int PmergeMe::calculate_nextJacobsthall()
{
	int nextJacobsthall = this->_currentJacobsthall + (this->_previousJacobsthall * 2);
	this->_previousJacobsthall = this->_currentJacobsthall;
	this->_currentJacobsthall = nextJacobsthall;
	return (nextJacobsthall);
}

void PmergeMe::insert(int index, unsigned int group_size, int b)
{
	if (index >= static_cast<int>(this->_pend.size())){
		std::cout << "HERE" << std::endl;
		index = this->_pend.size() - 1;
	}
	std::cout << "Value to insert into main: " << this->_pend[index] << "INDEX: " << index << std::endl;
	size_t next_index = group_size - 1;
	(void)group_size; //temp
	(void)b; //temp
	while(next_index < this->_main.size()){
		if (this->_main[next_index] > this->_pend[index])
			break ;
		next_index += group_size;
	}
	if (next_index >= this->_main.size()){
		for(size_t i = 0; i < group_size; ++i){
			this->_main.push_back(this->_pend[index - group_size + 1 + i]);
		}
	}
	else{
		for(size_t i = 0; i < group_size; ++i){
			std::cout << YELLOW << "NEXT INDEX: " << next_index << std::endl;
			std::cout << "INDEX: " << index << RESET << std::endl;
			this->_main.insert(this->_main.begin() + next_index - group_size + 1, this->_pend[index - i]);
		}
	}
	printVector("MAIN[", this->_main);
}

void PmergeMe::insertion(unsigned int group_size)
{
	int total_pairs_pend = this->_pend.size() / group_size;
	std::cout << "TOTAL PAIRS: " << total_pairs_pend << std::endl; //temp
	int currentJacobsthall = this->_currentJacobsthall;
	for(int i = 0; i < total_pairs_pend; ++i){
		std::cout << "CURRENT Jacobsthall number: " << currentJacobsthall << std::endl; //temp
		int difJacob = this->_currentJacobsthall - this->_previousJacobsthall;
		size_t index = currentJacobsthall * group_size - (group_size + 1);
		int b = 0;
		for(int j = 0; j < difJacob; ++j){
			b = currentJacobsthall - j;
			if (index < this->_pend.size())
				insert(index, group_size, b);
			index -= group_size;
		}
		currentJacobsthall = calculate_nextJacobsthall();
	}
	this->_currentJacobsthall = 3;
	this->_previousJacobsthall = 1;
	
	reassembleVector();
}

void PmergeMe::nextSteps(unsigned int group_size)
{
	size_t i = 1;
	while(i <= group_size){
		std::cout << "GROUP SIZE: " << group_size << std::endl;
		initialization(group_size);
		insertion(group_size); //TODO
		group_size /= 2;
	}
}

void PmergeMe::fordJohnsonAlgo(){
	unsigned int group_size = firstStep(1); //Division into pairs + sorting
	nextSteps(group_size); //initialization + insertion;
	
}

void PmergeMe::printVector(std::string str, std::vector<int> vector){
	for(size_t i = 0; i < vector.size(); ++i){
		std::cout << PINK << str << i << "]: " << vector[i] << RESET << std::endl;
	}
}

std::vector<int> PmergeMe::getInputVector(){
	return this->_inputVector;
}