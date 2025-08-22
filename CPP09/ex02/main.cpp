#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
		std::cout << GREEN << "This integer sequece is already sorted: " << argv[1] << RESET << std::endl;
	else if (argc > 1){
		try{
			PmergeMe container(argv);
			container.printVector("Before (Vector): ", PINK);
			container.fordJohnsonAlgo();
			container.printVector("After  (Vector): ", GREEN);
			container.printList("Before (List): " , PINK);
			container.fordJohnsonAlgoList();
			container.printList("After  (List): " , GREEN);
			std::cout << YELLOW << "Time to process a range of " << container.getInputVector().size() << " elements with std::vector ==> " << container.getTimeVector() << " microseconds" << RESET << std::endl;
			std::cout << YELLOW << "Time to process a range of " << container.getInputList().size() << " elements with std::list ==> " << container.getTimeList() << " microseconds" << RESET << std::endl;
		}catch(std::exception &e){
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}
	else
		std::cout << RED << "Not enoght arguments provided." << RESET << std::endl;
	return 0;
}