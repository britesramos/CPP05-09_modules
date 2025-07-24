#pragma once
#include <iostream>
#include <array>

template <typename T>
class Array{

	private:
		T* array;
		unsigned int len;

	public: 
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		Array& operator=(const Array& other);
		T& operator[](int idx);
		~Array();

		unsigned int size();

};

#include "Array.tpp"