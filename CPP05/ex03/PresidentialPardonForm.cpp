#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():AForm("PresidentialPardonForm", 25, 5, "Default target"){

}

PresidentialPardonForm::PresidentialPardonForm(std::string target):AForm("PresidentialPardonForm", 25, 5, target){
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other): AForm(other){

}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other){
	if (this != &other){
		AForm::operator=(other);
	}

	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){
	
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const{
	if (AForm::beExecuted(executor) == true){
		std::cout << AForm::getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	}
}