#include "Span.hpp"
#include <iostream>

void printVector(std::vector<int> vec)
{
	for(size_t i = 0; i < vec.size(); ++i){
		std::cout << PINK << vec[i] << RESET << std::endl;
	}
}

int main()
{
	std::cout << BLUE << "------------------------------------SUBJECT TEST" << RESET << std::endl;
	try{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		// sp.addNumber(78);
	
		// printVector(sp.getVec());
		std::cout << GREEN << sp.shortestSpan() << std::endl;
		// printVector(sp.getVec());
		std::cout << sp.longestSpan() << RESET << std::endl;
	}catch(std::exception &e){
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	std::cout << BLUE << "------------------------------------10 ELEMENTS TEST" << RESET << std::endl;
	
	try{
		Span sp1 = Span(10);
		sp1.addMultipleNumber();
		// printVector(sp1.getVec());
		std::cout << GREEN << sp1.shortestSpan() << std::endl;
		std::cout << sp1.longestSpan() << RESET << std::endl;
	}catch(std::exception &e){
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	std::cout << BLUE << "------------------------------------10000 ELEMENTS TEST" << RESET << std::endl;


	try{
		Span sp1 = Span(10000);
		sp1.addMultipleNumber();
		// printVector(sp1.getVec());
		std::cout << GREEN << sp1.shortestSpan() << std::endl;
		std::cout << sp1.longestSpan() << RESET << std::endl;
	}catch(std::exception &e){
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}


	return 0;
	}