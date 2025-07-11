#include "AForm.hpp"

#pragma once

class PresidentialPardonForm: public AForm
{
	public:
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm();

		void execute(Bureaucrat const & executor) const;
};