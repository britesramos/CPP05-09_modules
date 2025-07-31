#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>

#define GREEN "\033[32m"
#define RESET "\033[0m"
#define BLUE "\033[34m"
#define PINK "\033[35m"
#define YELLOW "\033[33m"
#define RED "\033[31m"

template <typename T>
void print_container(T container){
	for(size_t i = 0; i < container.size(); ++i){
		std::cout << PINK << container[i] << RESET << std::endl;
	}
}

int main()
{
	try{
		std::cout << BLUE << "----------------- INT VECTOR CONTAINER -----------------" << RESET << std::endl;
		std::vector<int> vec = {2, 3, 6, 89, 100};
		print_container(vec);
		std::vector<int>::iterator found = ::easyfind(vec, 6);
		std::cout << GREEN << "Found element: " << *found << RESET << std::endl;
		::easyfind(vec, 7);
	}catch (std::exception &e){
		std::cerr <<  RED << "Exception: " << e.what() << RESET << std::endl;
	}
	try{
		std::cout << BLUE << "----------------- INT DEQUE CONTAINER -----------------" << RESET << std::endl;
		std::deque<int> deq = {1, 7, 9};
		print_container(deq);
		std::deque<int>::iterator found = ::easyfind(deq, 9);
		std::cout << GREEN << "Found element: " << *found << RESET << std::endl;
		::easyfind(deq, 10);
	}catch (std::exception &e){
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}
	try{
		std::cout << BLUE << "------------------ INT LIST CONTAINER -----------------" << RESET << std::endl;
		std::list<int> list = {4314, 413, 416};
		// print_container(list); //List does not provide a subscript operator.
		std::list<int>::iterator found = ::easyfind(list, 413);
		std::cout << GREEN << "Found element: " << *found << RESET << std::endl;
		::easyfind(list, 10);
	}catch (std::exception &e){
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}
	try{
		std::cout << BLUE << "------------- INT FORWARD_LIST CONTAINER --------------" << RESET << std::endl;
		std::forward_list<int> list = {80753, 174091, 1};
		// print_container(list); //List does not provide a subscript operator.
		std::forward_list<int>::iterator found = ::easyfind(list, 1);
		std::cout << GREEN << "Found element: " << *found << RESET << std::endl;
		::easyfind(list, 10);
	}catch (std::exception &e){
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	return 0;
}