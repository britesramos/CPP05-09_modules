#include "Span.hpp"

Span::Span(unsigned int N): N(N){
	std::cout << YELLOW << "Span constructor called." << RESET << std::endl;
}

Span::Span(const Span& other): N(other.N), vec(other.vec){
	std::cout << YELLOW << "Span copy constructor called." << RESET << std::endl;

}

Span& Span::operator=(const Span& other){
	std::cout << YELLOW << "Span copy assignment operator called." << RESET << std::endl;
	if (this != &other){
		this->N = other.N;
		this->vec = other.vec;
	}
	return *this;
}

Span::~Span(){
	std::cout << YELLOW << "Span default destructor called." << RESET << std::endl;
}

void Span::addNumber(unsigned int i){
	if (this->vec.size() >= this->N)
		throw std::logic_error("Size limit reached for this container.");
	this->vec.push_back(i);
}


unsigned int Span::shortestSpan(){
	if (this->vec.size() < 2)
		throw std::logic_error ("Not enough elements to perform shortestSpan().");
	std::sort(this->vec.begin(), this->vec.end());
	unsigned int shortest = UINT_MAX;
	std::adjacent_find(this->vec.begin(), this->vec.end(),
					[&shortest](int a, int b){ //Lambdas can mutate variables from other scopes if captured them by reference
						shortest = std::min(shortest, static_cast<unsigned int>(b - a)); //Updates shortest, if the difference between b and a is smaller than the current shortest.
						return false; //Returning false insures that the adjacent_find algorithm with iterate over the entire vector.
					});
	return shortest;
}

unsigned int Span::longestSpan(){
	if (this->vec.size() < 2)
		throw std::logic_error ("Not enough elements to perform longestSpan().");
	std::vector<int>::iterator min = std::min_element(vec.begin(), vec.end());
	std::vector<int>::iterator max = std::max_element(vec.begin(), vec.end());
	return *max - *min;
}

void Span::addMultipleNumber(){
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(1, 1000);

	unsigned int remaining_space = this->N - this->vec.size();
	if (remaining_space == 0)
		throw std::logic_error("No space left in the container.");
	for (size_t i = 0; i < remaining_space; ++i){
		int randomValue = dist(gen);
		this->vec.push_back(randomValue);
	}
}

std::vector<int> Span::getVec(){
	return this->vec;
}