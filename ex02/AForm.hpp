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

		const std::string target;

	public:
		AForm();
		AForm(std::string name, int gradeToSign, int gradeToExecute, std::string target);
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

		class GradeTooLowToExecute: public std::exception{
			public:
				const char* what() const noexcept override;
		};

		const std::string getName() const;
		bool getIsSigned();
		int getGradeToSign();
		int getGradeToExecute();

		const std::string getTarget() const;

		void beSigned(Bureaucrat& bureaucrat);
		bool beExecuted(Bureaucrat const& bureaucrat) const;

		virtual void execute(Bureaucrat const & executor) const = 0;

};

std::ostream &operator<<(std::ostream &os, AForm &form);