#include "AForm.hpp"

#pragma once

class ShrubberyCreationForm: public AForm
{
	public:
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();

		void execute(Bureaucrat const & executor) const;
	
};