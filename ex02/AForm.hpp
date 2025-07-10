#include <string>
#include <cstdbool>
#include <iostream>

#pragma once

class Bureaucrat;

class AForm
{
	private:
		const	std::string name;
		bool	isSigned;
		const int	gradeToSign;
		const int 	gradeToExecute;

	public:
		AForm();
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		~AForm();
	
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

std::ostream &operator<<(std::ostream &os, AForm &form);