
#pragma once

#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include <limits.h>

#define GREEN "\033[32m"
#define RESET "\033[0m"
#define BLUE "\033[34m"
#define PINK "\033[35m"
#define YELLOW "\033[33m"
#define RED "\033[31m"

class Span{
	private:
		unsigned int N;
		std::vector<int> vec;

	public:
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();


		void addNumber(unsigned int i);
		unsigned int shortestSpan();
		unsigned int longestSpan();
		
		void addMultipleNumber();
		std::vector<int> getVec();

};