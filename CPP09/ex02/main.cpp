#include "PmergeMe.hpp"

void printVector(std::string str, std::vector<int> vector){
	std::cout << str;
	for(size_t i = 0; i < vector.size(); ++i)
		std::cout << vector[i] << " ";
	std::cout << std::endl;
}

int main(int argc, char **argv)
{
	if (argc == 2)
		std::cout << GREEN << "This integer sequece is already sorted: " << argv[1] << RESET << std::endl;
	else if (argc > 1){
		try{
			PmergeMe vector(argv);
			printVector("Before: ", vector.getInputVector());
			vector.fordJohnsonAlgo();
			printVector("After: ", vector.getInputVector());
		}catch(std::exception &e){
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}
	else
		std::cout << RED << "Not enoght arguments provided." << RESET << std::endl;
	return 0;
}