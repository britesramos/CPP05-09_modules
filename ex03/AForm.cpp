#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): name("Default_Form_Name"), isSigned(false), gradeToSign(0), gradeToExecute(0), target("DefaultTarget"){
	std::cout << "Form constructor called for form: " << this->name << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute, std::string target): name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute), target(target){
	std::cout << "Form constructor called for form: " << this->name << std::endl;
}

AForm::AForm(const AForm &other): name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute){
}

AForm& AForm::operator=(const AForm &other){
	if (this != &other){
		// this->name = other.name;
		this->isSigned = other.isSigned;
		// this->gradeToExecute = other.gradeToExecute;
		// this->gradeToSign = other.gradeToSign;
	}
	return *this;
}

AForm::~AForm(){
	std::cout << "Form destructor called for form: " << this->name << std::endl;
}

const char* AForm::GradeTooHighException::what() const noexcept{
	return "Form grade too high.";
}

const char* AForm::GradeTooLowException::what() const noexcept{
	return "Form grade too low.";
}

const char* AForm::GradeTooLowToExecute::what() const noexcept{
	return ("Form grade too low to Execute.");
}

const std::string AForm::getName() const{
	return this->name;
}

bool AForm::getIsSigned(){
	return this->isSigned;
}

int AForm::getGradeToSign(){
	return this->gradeToSign;
}

int AForm::getGradeToExecute(){
	return this->gradeToExecute;
}

const std::string AForm::getTarget() const{
	return this->target;
}

void AForm::beSigned(Bureaucrat& bureaucrat){
	if (bureaucrat.getGrade() <= this->gradeToSign){
		this->isSigned = true;
	}
	else
		throw GradeTooLowException();
}

bool AForm::beExecuted(Bureaucrat const& bureaucrat) const{
	if (this->isSigned){
		if (bureaucrat.getGrade() <= this->gradeToExecute)
			return true;
		else{
			throw GradeTooLowToExecute();
			return false;
		}
	}
	else
		std::cout << bureaucrat.getName() << " can not execute: " << this->name << " because it is not signed." << std::endl;
	return false;
}

std::ostream &operator<<(std::ostream &os, AForm &form){
	os << "\n\n-------FORM INFO-------\n\n->Form name: " << form.getName()
		<< "\n->isSigned?: " << form.getIsSigned()
		<< "\n->Grade to sign: " << form.getGradeToSign()
		<< "\n->Grade to execute: " << form.getGradeToExecute()
		<<"\n->Target: " << form.getTarget()
		<< "\n------------------------\n\n";
	return os;
}
