#include <string>
#include <cstdbool>
#include <iostream>

#pragma once

class Bureaucrat;

class Form
{
	private:
		const	std::string name;
		bool	isSigned;
		const int	gradeToSign;
		const int 	gradeToExecute;

	public:
		Form();
		Form(std::string name, int gradeToSign, int gradeToExecute);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();
	
		class GradeTooHighException: public std::exception{
			public:
				const char* what() const noexcept override;
		};

		class GradeTooLowException: public std::exception{
			public:
				const char* what() const noexcept override;
		};

		const std::string getName();
		bool getIsSigned();
		int getGradeToSign();
		int getGradeToExecute();

		void beSigned(Bureaucrat& bureaucrat);

};

std::ostream &operator<<(std::ostream &os, Form &form);