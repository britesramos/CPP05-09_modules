#include "Array.hpp"

int main()
{
	try{
		std::cout << BLUE << "-----------------------------STR-----------------------------" << RESET << std::endl;
		Array<std::string> str(5);
		
		for (unsigned int a = 0; a < str.size(); ++a){
			str[a] = 'A' + a;
		}

		std::cout << "Size of str: " << str.size() << std::endl;
		
		for (unsigned int b = 0; b < str.size(); ++b){
			std::cout << GREEN << str[b] << RESET << std::endl;
		}

		std::cout << BLUE << "\n\n------------------------------B------------------------------" << RESET << std::endl;
		Array<int> b(10);
		std::cout << "Size of b: " << b.size() << std::endl;
		
		
		for(unsigned int i = 0; i < b.size(); ++i){
			b[i] = i + 10;
		}
		
		for(unsigned int j = 0; j < b.size(); ++j){
			std::cout << GREEN << b[j] << RESET << std::endl; 
		}
		
		std::cout << BLUE << "\n\n-------------------------------A-----------------------------" << RESET << std::endl;
		Array<int> a;
		std::cout << "Size of a: " << a.size() << std::endl;

		// std::cout << GREEN << a[0] << RESET << std::endl; //Out of bounds.
		a = b;
		for (unsigned int b = 0; b < a.size(); ++b){
			std::cout << GREEN << a[b] << RESET << std::endl;
		}

		
		std::cout << BLUE << "\n\n----------------------------STR1-----------------------------" << RESET << std::endl;
		Array<std::string> str1(str);
		std::cout << "Size of str1: " << str1.size() << std::endl;
		
		std::cout << BLUE << "This is STR1: " << RESET << std::endl;
		for (unsigned int b = 0; b < str1.size(); ++b){
			std::cout << GREEN << str1[b] << RESET << std::endl;
		}

		std::cout << "Changing str1.." << std::endl;

		for (unsigned int c = 0; c < str1.size(); ++c){
			str1[c] = 'F' + c;
		}

		std::cout << BLUE << "This is STR:" << RESET << std::endl;
		for (unsigned int b = 0; b < str.size(); ++b){
			std::cout << GREEN << str[b] << RESET << std::endl;
		}

		std::cout << BLUE << "This is STR1: " << RESET << std::endl;
		for (unsigned int b = 0; b < str1.size(); ++b){
			std::cout << GREEN << str1[b] << RESET << std::endl;
		}


	}catch(std::exception& e){
		std::cerr << "Exception: " << e.what() << std::endl;

	}


	return 0;
}