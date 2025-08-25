#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **argv){
	// std::cout << YELLOW << "PmergeMe constructor called." << RESET << std::endl;
	parseInput(argv);
}

PmergeMe::PmergeMe(const PmergeMe& other){
	*this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other){
	if (this != &other){
		this->_inputSize = other._inputSize;
		this->_inputVector = other._inputVector;
		this->_pairs = other._pairs;
		this->_main = other._main;
		this->_pend = other._pend;
		this->_nonParticipating = other._nonParticipating;
		this->_currentJacobsthall = other._currentJacobsthall;
		this->_previousJacobsthall = other._previousJacobsthall;
		this->_timeVector = other._timeVector;
	}
	return *this;
}


PmergeMe::~PmergeMe(){
	// std::cout << YELLOW << "PmergeMe destructor called." << RESET << std::endl;
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
		if (isValidInput(argv[i])){
			this->_inputVector.push_back(std::atoi(argv[i]));
			this->_inputList.push_back(std::atoi(argv[i]));
		}
		i++;
	}
	this->_inputSize = this->_inputVector.size();
}

//Ford Johnson Algorithm Vector implementation

void PmergeMe::initPairs(unsigned int group_size){

	unsigned int j = 1;
	this->_pairs.clear();
	for(unsigned int i = 0; i < (this->_inputSize / (group_size * 2)); ++i){
		this->_pairs.insert({(group_size * j) - 1, {this->_inputVector[(group_size * j) - 1],this->_inputVector[(group_size * (j + 1)) - 1]}});
		j += 2;
	}
}

void PmergeMe::ft_swap(size_t i, unsigned int group_size)
{
	for(size_t j = 0; j < group_size; ++j){
		std::swap(this->_inputVector[i - j], this->_inputVector[i + group_size - j]);
	}
}

unsigned int PmergeMe::firstStep(unsigned int group_size){
	if (this->_inputSize / (group_size * 2) < 1)
		return (group_size);
	initPairs(group_size);
	for (const auto& [key, value] : this->_pairs){
		auto [a, b] = this->_pairs[key];
		if (a > b)
			ft_swap(key, group_size);
	}
	return firstStep(group_size * 2);
}

// void debug(std::vector<int> vector){
// 	for(size_t j = 0; j < vector.size(); ++j){
// 		std::cout << PINK << "VECTOR[" << j << "]: " << vector[j] << std::endl;
// 	}
// }

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
	// std::cout << "GROUP_SIZE: " << group_size << std::endl;
	// std::cout << YELLOW << "MAIN: " << std::endl;
	// debug(this->_main);
	// std::cout << YELLOW << "PEND: " << std::endl;
	// debug(this->_pend);
	// std::cout << YELLOW << "NON_P: " << std::endl;
	// debug(this->_nonParticipating);

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

void PmergeMe::insert(int index, unsigned int group_size)
{
	if (index >= static_cast<int>(this->_pend.size()))
		index = this->_pend.size() - 1;
	// std::cout << "Value to insert into main: " << this->_pend[index] << " ==== INDEX: " << index << std::endl; //temp
	size_t next_index = group_size - 1;
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
			this->_main.insert(this->_main.begin() + next_index - group_size + 1, this->_pend[index - i]);
		}
	}
}

void PmergeMe::insertion(unsigned int group_size)
{
	int total_pairs_pend = this->_pend.size() / group_size;
	int currentJacobsthall = this->_currentJacobsthall;
	for(int i = 0; i < total_pairs_pend; ++i){
		int difJacob = this->_currentJacobsthall - this->_previousJacobsthall;
		size_t index = currentJacobsthall * group_size - (group_size + 1);
		for(int j = 0; j < difJacob; ++j){
			if (index < this->_pend.size())
				insert(index, group_size);
			index -= group_size;
		}
		++i; //Double iteration?
		currentJacobsthall = calculate_nextJacobsthall();
	}
	this->_currentJacobsthall = 3;
	this->_previousJacobsthall = 1;
	reassembleVector();
}

void PmergeMe::nextSteps(unsigned int group_size)
{
	size_t i = 1;
	while(group_size >= i){
		// printVector("         VECTOR: ", BLUE); //delete
		// std::cout << "SIZE: " << this->_inputVector.size() << std::endl; //delete
		initialization(group_size);
		insertion(group_size);
		group_size /= 2;
	}
}

void PmergeMe::fordJohnsonAlgo(){
	auto start = std::chrono::high_resolution_clock::now();
	unsigned int group_size = firstStep(1); //Division into pairs + sorting
	group_size /= 2;
	nextSteps(group_size); //initialization + insertion;
	auto end = std::chrono::high_resolution_clock::now();
	this->_timeVector = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}


//Ford Johnson Algorithm List implementation
void PmergeMe::initPairsList(unsigned int group_size){

	unsigned int j = 1;
	this->_pairsList.clear();
	for(unsigned int i = 0; i < (this->_inputSize / (group_size * 2)); ++i){
		auto it1 = this->_inputList.begin();
		auto it2 = this->_inputList.begin();
		std::advance(it1, (group_size * j) - 1);
		std::advance(it2, (group_size * (j + 1)) - 1);
		this->_pairsList.insert({(group_size * j) - 1, {*it1, *it2}});
		j += 2;
	}
}

void PmergeMe::ft_swapList(size_t i, unsigned int group_size)
{
	for(size_t j = 0; j < group_size; ++j){
		auto it1 = this->_inputList.begin();
		std::advance(it1, i - j);
		auto it2 = this->_inputList.begin();
		std::advance(it2, i + group_size - j);
		std::swap(*it1, *it2);
	}
}

unsigned int PmergeMe::firstStepList(unsigned int group_size){
	if (this->_inputSize / (group_size * 2) < 1)
		return (group_size);
	initPairsList(group_size);
	for (const auto& [key, value] : this->_pairsList){
		auto [a, b] = this->_pairsList[key];
		if (a > b)
			ft_swapList(key, group_size);
	}
	return firstStepList(group_size * 2);
}

void PmergeMe::initializationList(unsigned int group_size)
{
	this->_mainList.clear();
	this->_pendList.clear();
	this->_nonParticipatingList.clear();
	for(size_t j = 0; j < (group_size * 2); ++j){
		auto it = this->_inputList.begin();
		std::advance(it, j);
		this->_mainList.push_back(*it);
	}
	size_t i = group_size * 2;
	while(i < this->_inputList.size()){
		if ((i + group_size) > this->_inputList.size()){
			while(i < this->_inputList.size()){
				auto it = this->_inputList.begin();
				std::advance(it, i);
				this->_nonParticipatingList.push_back(*it);
				i++;
			}
			break ;
		}
		else{
			for(size_t a = 0; a < group_size && i < this->_inputList.size(); ++a){
				auto it = this->_inputList.begin();
				std::advance(it, i);
				this->_pendList.push_back(*it);
				i++;
			}
			if (!((i + group_size) > this->_inputList.size())){
				for(size_t a = 0; a < group_size && i < this->_inputList.size(); ++a){
					auto it = this->_inputList.begin();
					std::advance(it, i);
					this->_mainList.push_back(*it);
					i++;
				}
			}
		}
	}
}

void PmergeMe::reassembleList()
{
	this->_inputList.clear();
	this->_inputList.insert(this->_inputList.end(), this->_mainList.begin(), this->_mainList.end());
	if (!this->_nonParticipatingList.empty())
		this->_inputList.insert(this->_inputList.end(), this->_nonParticipatingList.begin(), this->_nonParticipatingList.end());
}

void PmergeMe::insertList(int index, unsigned int group_size)
{
	if (index >= static_cast<int>(this->_pendList.size()))
		index = this->_pendList.size() - 1;
	size_t next_index = group_size - 1;
	while(next_index < this->_mainList.size()){
		auto mL = this->_mainList.begin();
		std::advance(mL, next_index);
		auto pL = this->_pendList.begin();
		std::advance(pL, index);
		if (*mL > *pL)
			break ;
		next_index += group_size;
	}
	if (next_index >= this->_mainList.size()){
		for(size_t i = 0; i < group_size; ++i){
			auto pL = this->_pendList.begin();
			std::advance(pL, index - group_size + 1 + i);
			this->_mainList.push_back(*pL);
		}
	}
	else{
		for(size_t i = 0; i < group_size; ++i){
			auto mL = this->_mainList.begin();
			std::advance(mL, next_index - group_size + 1);
			auto pL = this->_pendList.begin();
			std::advance(pL, index - i);
			this->_mainList.insert(mL, *pL);
		}
	}
}

void PmergeMe::insertionList(unsigned int group_size)
{
	int total_pairs_pend = this->_pendList.size() / group_size;
	int currentJacobsthall = this->_currentJacobsthall;
	for(int i = 0; i < total_pairs_pend; ++i){
		int difJacob = this->_currentJacobsthall - this->_previousJacobsthall;
		size_t index = currentJacobsthall * group_size - (group_size + 1);
		for(int j = 0; j < difJacob; ++j){
			if (index < this->_pendList.size())
				insertList(index, group_size);
			index -= group_size;
		}
		++i; //Double iteration?
		currentJacobsthall = calculate_nextJacobsthall();
	}
	this->_currentJacobsthall = 3;
	this->_previousJacobsthall = 1;
	reassembleList();
}

void PmergeMe::nextStepsList(unsigned int group_size)
{
	size_t i = 1;
	while(group_size >= i){
		initializationList(group_size);
		insertionList(group_size);
		group_size /= 2;
	}
}

void PmergeMe::fordJohnsonAlgoList(){
	auto start = std::chrono::high_resolution_clock::now();
	unsigned int group_size = firstStepList(1); //Division into pairs + sorting
	group_size /= 2;
	nextStepsList(group_size); //initialization + insertion;
	auto end = std::chrono::high_resolution_clock::now();
	this->_timeList = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

//Printing...

void PmergeMe::printVector(std::string str, std::string color){
	std::cout << color << str;
	for(size_t i = 0; i < this->_inputSize; ++i){
		std::cout << this->_inputVector[i] << " ";
	}
	std::cout << RESET << std::endl;
}


void PmergeMe::printList(std::string str, std::string color){
    std::cout << color << str;
    for(const auto& elem : this->_inputList){
        std::cout << elem << " ";
    }
    std::cout << RESET << std::endl;
}

//Getters:

std::vector<int> PmergeMe::getInputVector(){
	return this->_inputVector;
}

std::list<int> PmergeMe::getInputList(){
	return this->_inputList;
}

int PmergeMe::getTimeVector(){
	return this->_timeVector;
}

int PmergeMe::getTimeList(){
	return this->_timeList;
}