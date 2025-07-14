#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(){
	try{
		Bureaucrat rosa ("Rosa", 1);
		Bureaucrat bob("Bob", 50);
		Bureaucrat jack("Jack", 146);
		ShrubberyCreationForm default_shrubbery;
		std::cout << default_shrubbery << std::endl;
		ShrubberyCreationForm berry("Berry");
		PresidentialPardonForm president("President");
		RobotomyRequestForm robot("Robot");

		std::cout << "\n\n" << rosa << std::endl;
		std::cout << bob << std::endl;
		std::cout << jack << "\n\n" << std::endl;

		std::cout << berry << std::endl;
		std::cout << president << std::endl;
		std::cout << robot << std::endl;

		bob.signForm(president);
		jack.signForm(president);
		rosa.signForm(president);
		std::cout << "\n\n" << std::endl;
		
		bob.executeForm(president);
		jack.executeForm(president);
		rosa.executeForm(president);
		std::cout << "\n\n" << std::endl;

		jack.signForm(berry);
		jack.incrementGrade();
		jack.signForm(berry);
		rosa.executeForm(berry);
		std::cout << "\n\n" << std::endl;

		bob.signForm(robot);
		for (int i = 0; i < 20; ++i)
			rosa.executeForm(robot);
		std::cout << "\n\n" << std::endl;

		rosa.incrementGrade();
	}
	catch (std::exception &e){
		std::cerr << "\nException: " << e.what() << std::endl;
	}
	
}