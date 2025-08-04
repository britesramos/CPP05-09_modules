#pragma once

#include <deque>
#include <stack>
#include <iostream>

#define GREEN "\033[32m"
#define RESET "\033[0m"
#define BLUE "\033[34m"
#define PINK "\033[35m"
#define YELLOW "\033[33m"
#define RED "\033[31m"

template <typename T>
class MutantStack: public std::stack<T, std::deque<T>>{ //By default std::stack uses deque as the underlying container.
	public:
		MutantStack();
		MutantStack(const MutantStack& other);
		MutantStack& operator=(const MutantStack& other);
		~MutantStack();

		using iterator = typename std::deque<T>::iterator;
		using const_iterator = typename std::deque<T>::const_iterator;
		using reverse_iterator = typename std::deque<T>::reverse_iterator;
		using const_reverse_iterator = typename std::deque<T>::const_reverse_iterator;
		
		iterator begin();
		iterator end();
		const_iterator cbegin() const;
		const_iterator cend() const;
		reverse_iterator rbegin();
		reverse_iterator rend();
		const_reverse_iterator crbegin() const;
		const_reverse_iterator crend() const;
};

#include "MutantStack.tpp"