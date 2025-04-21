#include <string>
#include <iostream>
#include <exception>

#pragma once

class Bureaucrat{
	private:
		const std::string name;
		int grade;
	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();

		int getGrade();
		std::string getName();

		void incrementGrade();
		void decrementGrade();

		class GradeTooHighException: public std::exception{
			public:
				const char* what() const noexcept override;
		};
		class GradeTooLowException: public std::exception{
			public:
				const char* what() const noexcept override;
		};
};

std::ostream &operator<<(std::ostream &os, Bureaucrat &bureaucrat);
