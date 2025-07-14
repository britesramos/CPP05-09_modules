#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(){

}

Intern::~Intern(){
	std::cout << "Intern default destructor called." << std::endl;
}

const char* Intern::FormDoesNotExist::what() const noexcept{
	return "Form requested does not exist!";
}

AForm* Intern::createPresidential(std::string &target){
	return new PresidentialPardonForm(target);
}

AForm* Intern::createRobotomy(std::string &target){
	return new RobotomyRequestForm(target);
}

AForm* Intern::createShrubbery(std::string &target){
	return new ShrubberyCreationForm(target);
}

typedef AForm* (*FormCreator)(std::string&);

AForm* Intern::makeForm(std::string formName, std::string target){
	const std::string form_names[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	FormCreator creators[] = {createPresidential, createRobotomy, createShrubbery};
	
	for (int i = 0; i < 3; ++i){
		if (formName == form_names[i]){
			std::cout << "Intern creates: " << formName << std::endl;
			return creators[i](target);
		}
	}
	throw FormDoesNotExist();
}