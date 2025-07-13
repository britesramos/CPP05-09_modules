#include "AForm.hpp"

#pragma once

class Intern
{
	public:
		Intern();
		~Intern();

		class FormDoesNotExist: public std::exception{
			public:
				const char* what() const noexcept override;
		};

		static AForm* createPresidential(std::string &target);
		static AForm* createRobotomy(std::string &target);
		static AForm* createShrubbery(std::string &target);
		AForm* makeForm(std::string formName, std::string target);
};