#include "Bureaucrat.hpp"

int main(){
	
	Bureaucrat bob("Bob", 1);
	Bureaucrat tom("Tom", 150);
	try {
		// Bureaucrat a("Marie", 0);
		// Bureaucrat b("John", 151);
		std::cout << bob << std::endl;
		std::cout << tom << std::endl;
		// std::cout << a << std::endl;
		// std::cout << b << std::endl;
		// tom.decrementGrade();
		tom.incrementGrade();
		bob.decrementGrade();
		bob.incrementGrade();
		bob.incrementGrade();
		std::cout << bob << std::endl;
		std::cout << tom << std::endl;
		// std::cout << a << std::endl;
		// std::cout << b << std::endl;
	} catch (const Bureaucrat::GradeTooHighException &e) {
		std::cerr << e.what() << std::endl;
	} catch (const Bureaucrat::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << bob << std::endl;
	std::cout << tom << std::endl;
	return 0;
}