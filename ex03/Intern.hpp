#include "AForm.hpp"

#pragma once

class Intern
{
	public:
		Intern();
		~Intern();

		AForm* makeForm(std::string formName, std::string target);
};