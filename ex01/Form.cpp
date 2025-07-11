#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): name("Default_Form_Name"), isSigned(false), gradeToSign(0), gradeToExecute(0){
	std::cout << "Form constructor called for form: " << this->name << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute): name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute){
	std::cout << "Form constructor called for form: " << this->name << std::endl;
}

Form::Form(const Form &other): name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute){
}

Form& Form::operator=(const Form &other){
	if (this != &other){
		// this->name = other.name;
		this->isSigned = other.isSigned;
		// this->gradeToExecute = other.gradeToExecute;
		// this->gradeToSign = other.gradeToSign;
	}
	return *this;
}

Form::~Form(){
	std::cout << "Form destructor called for form: " << this->name << std::endl;
}

const char* Form::GradeTooHighException::what() const noexcept{
	return "Form grade too high.";
}

const char* Form::GradeTooLowException::what() const noexcept{
	return "Form grade too low.";
}

const std::string Form::getName(){
	return this->name;
}

bool Form::getIsSigned(){
	return this->isSigned;
}

int Form::getGradeToSign(){
	return this->gradeToSign;
}

int Form::getGradeToExecute(){
	return this->gradeToExecute;
}

void Form::beSigned(Bureaucrat& bureaucrat){
	if (bureaucrat.getGrade() <= this->gradeToSign)
		this->isSigned = true;
	else
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, Form &form){
	os << "\n\n-------FORM INFO-------\n\n->Form name: " << form.getName()
		<< "\n->isSigned?: " << form.getIsSigned()
		<< "\n->Grade to sign: " << form.getGradeToSign()
		<< "\n->Grade to execute: " << form.getGradeToExecute()
		<< "\n------------------------\n\n";
	return os;
}
