#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target):AForm("RobotomyRequestForm", 72, 45, target){
}

RobotomyRequestForm::~RobotomyRequestForm(){
	
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	//Makes some drilling noises, then informs that <target> has been robotomized successfully 50% of the time.
	//Otherwise, it informs that the robotomy failed.
	std::cout << "---Drilling noises---" << std::endl;
	if (rand() % 2 == 0)
	{
		if (AForm::beExecuted(executor) == true)
			std::cout << AForm::getTarget() << " has been robotomized successfully." << std::endl;

	}
	else
		std::cout << "Robotomized failed on: " << AForm::getTarget() << std::endl;
}
