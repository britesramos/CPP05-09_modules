#include "Bureaucrat.hpp"

int main(){
	Bureaucrat bob("Bob", 1);
	Bureaucrat tom("Tom", 150);
	try {
		// Bureaucrat bob("Bob", 0);
		// Bureaucrat tom("Tom", 150);
		std::cout << bob << std::endl;
		std::cout << tom << std::endl;
		tom.decrementGrade();
		tom.incrementGrade();
		bob.decrementGrade();
		// bob.incrementGrade();
		// bob.incrementGrade();
		// std::cout << bob << std::endl;
		// std::cout << tom << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Exception: "<< e.what() << std::endl;
	}
	std::cout << bob << std::endl;
	std::cout << tom << std::endl;
	return 0;
}