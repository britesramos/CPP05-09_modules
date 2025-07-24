#include "iter.hpp"
#include <iostream>
#include <array>

void increment(int& i)
{
	i = i + 10;
}

template <typename T>
void print(const T& thing){
	std::cout << thing << std::endl;
}

int main()
{
	int array_size = 10;
	int array[array_size];
	for (int i = 0; i < array_size; ++i){
		array[i] = i;
	}
	std::cout << "BEFORE ITER (non const parameter): " << std::endl;
	iter(array, array_size, print<int>);
	iter(array, array_size, increment);
	std::cout << "\n-----------------------------------------------------\n" << std::endl;
	std::cout << "AFTER ITER (non const parameter): " << std::endl;
	iter(array, array_size, print<int>);

	std::cout << "\n-----------------------------------------------------\n" << std::endl;

	std::cout << "AFTER ITER (const parameter): " << std::endl;
	const std::array<std::string, 3> str_arr = {"A", "B", "C"};
	iter(str_arr.data(), str_arr.size(), print<std::string>);


	
	return 0;
}