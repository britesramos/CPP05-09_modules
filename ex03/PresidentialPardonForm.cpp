#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target):AForm("PresidentialPardonForm", 25, 5, target){
}

PresidentialPardonForm::~PresidentialPardonForm(){
	
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const{
	if (AForm::beExecuted(executor) == true){
		std::cout << AForm::getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	}
}