#pragma once

#include <deque>
#include <stack>

//Make std::stack container iterable.

#define GREEN "\033[32m"
#define RESET "\033[0m"
#define BLUE "\033[34m"
#define PINK "\033[35m"
#define YELLOW "\033[33m"
#define RED "\033[31m"

template <typename T>
class MutantStack: public std::stack<T, std::deque<T>>{
	public:
		MutantStack();
		MutantStack(const MutantStack& other);
		MutantStack& operator=(const MutantStack& other);
		~MutantStack();

		//Basic operations:
		// void push(const T& n);
		// T& top(void);
		// void pop(void);
		// //Other operations:
		// void push_range();
		// void emplace();
		// size_t size();
		// bool empty();
		// void swap();

		// //Missing iteration operation:
		iterators();

		// //Getters
		// T* getStack();
};

// #include "MutantStack.tpp"