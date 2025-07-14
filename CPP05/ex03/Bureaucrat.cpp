#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name(""), grade(0){
	std::cout << "Bureaucrat default constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): name(name){
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
	std::cout << "Constructor called for Bureaucrat: " << this->name << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): name(other.name), grade(other.grade) {
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other) {
		this->grade = other.grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Destructor called for Bureaucrat: " << this->name << std::endl;
}

std::string Bureaucrat::getName() const{
	return (this->name);
}

int Bureaucrat::getGrade() const{
	return (this->grade);
}

void Bureaucrat::incrementGrade(){
	if (this->grade == 1)
		throw GradeTooHighException();
	this->grade--;
}

void Bureaucrat::decrementGrade(){
	if (this->grade == 150)
		throw GradeTooLowException();
	this->grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept {
	return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept {
	return "Grade is too low!";
}

void Bureaucrat::signForm(AForm& form){
	try{
		form.beSigned(*this);
		std::cout << this->name << " signed: " << form.getName() << "." << std::endl;
	}
	catch(std::exception e){
		std::cout << this->name << " couldn't sign: " << form.getName() << "." << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form){
	try{
		form.execute(*this);
		std::cout << this->name << " executed: " << form.getName() << "." << std::endl;
	}
	catch(std::exception e){
		std::cout << this->name << " couldn't execute: " << form.getName() << "." << std::endl;
	}
}

std::ostream &operator<<(std::ostream &os, Bureaucrat &bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}