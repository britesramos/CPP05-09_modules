#include "Array.hpp"

int main()
{
	try{
		
		Array<std::string> str(5);
		std::cout << "Size of str: " << str.size() << std::endl;
		
		for (unsigned int a = 0; a < str.size(); ++a){
			str[a] = 'A' + a;
		}
		
		std::cout << BLUE << "\n\n-----------------------------STR-----------------------------" << RESET << std::endl;
		
		for (unsigned int b = 0; b < str.size(); ++b){
			std::cout << GREEN << str[b] << RESET << std::endl;
		}

		std::cout << BLUE << "\n\n------------------------------------------------------------" << RESET << std::endl;
		Array<int> b(10);
		std::cout << BLUE << "\n\n------------------------------B------------------------------" << RESET << std::endl;
		std::cout << "Size of b: " << b.size() << std::endl;
		
		
		for(unsigned int i = 0; i < b.size(); ++i){
			b[i] = i + 10;
		}
		
		// for(unsigned int j = 0; j < b.size() + 1; ++j){
		// 	std::cout << GREEN << b[j] << RESET << std::endl; 
		// }
		std::cout << BLUE << "\n\n------------------------------------------------------------" << RESET << std::endl;
		
		Array<int> a;
		std::cout << "Size of a: " << a.size() << std::endl;

		std::cout << BLUE << "\n\n-----------------------------A-----------------------------" << RESET << std::endl;

		// std::cout << GREEN << a[0] << RESET << std::endl; //Out of bounds.
		a = b;
		std::cout << GREEN << a[0] << RESET << std::endl;

		Array<std::string> str1(str);

		std::cout << BLUE << "\n\n-----------------------------STR1-----------------------------" << RESET << std::endl;
		
		for (unsigned int b = 0; b < str1.size(); ++b){
			std::cout << GREEN << str1[b] << RESET << std::endl;
		}



	}catch(std::exception& e){
		std::cerr << "Exception: " << e.what() << std::endl;

	}


	return 0;
}