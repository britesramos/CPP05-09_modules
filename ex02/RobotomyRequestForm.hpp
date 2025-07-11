#include "AForm.hpp"

#pragma once

class RobotomyRequestForm: public AForm
{
	public:
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();

		void execute(Bureaucrat const & executor) const;
};