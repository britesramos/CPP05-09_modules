#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack(){
	std::cout << YELLOW << "MutantStack Default Constructor called." << RESET << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& other){
	*this = other;
	std::cout << YELLOW << "MutantStack Copy Constructor called." << RESET << std::endl;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& other){
	std::cout << YELLOW << "MutantStack Copy Assignment Operator called." << RESET << std::endl;
	if (this != &other){
		this->c = other.c;
	}
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack(){
	std::cout << YELLOW << "MutantStack Default Destructor called." << RESET << std::endl;
}


// template <typename T>
// void MutantStack<T>::push(){

// }