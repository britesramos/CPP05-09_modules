#include "Array.hpp"

#define GREEN "\033[32m"
#define RESET "\033[0m"
#define BLUE "\033[34m"
#define PINK "\033[35m"
#define YELLOW "\033[33m"
#define RED "\033[31m"

template <typename T>
Array<T>::Array(): array(nullptr), len(0){
	std::cout << YELLOW << "Array default constructor called." << RESET << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n): array(new T[n]()), len(n){
	std::cout << YELLOW << "Array template constructor called." << RESET << std::endl;
}

template <typename T>
Array<T>::Array(const Array& other): array(nullptr), len(other.len){
	if (len > 0){
		array = new T[len];
		for (unsigned int i = 0; i < len; ++i){
			this->array[i] = other.array[i];
		}
	}
	std::cout << "Array copy constructor called." << std::endl;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other){
	if (this != &other){
		delete[] this->array;
		this->len = other.len;
		this->array = (this->len > 0) ? new T(this->len()) : nullptr;
		for (unsigned int i = 0; i < this->len; ++i)
		{
			this->array[i] = other.array[i];
		}
	}
	std::cout << "Copy assignment operator called." << std::endl;
	return *this;

}

template <typename T>
T& Array<T>::operator[](int idx){
	if (idx < 0 || static_cast<unsigned int>(idx) >= this->len)
		throw std::out_of_range("Index out of bounds");
	return this->array[idx];
}

template <typename T>
Array<T>::~Array(){
	delete[] this->array;
	std::cout << RED << "Default destructor called." << RESET << std::endl;
}

template <typename T>
unsigned int Array<T>::size(){
	return this->len;
}