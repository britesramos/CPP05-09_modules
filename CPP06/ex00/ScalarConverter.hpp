#pragma once

#include <string>
#include <iostream>


class ScalarConverter
{

	private:
		ScalarConverter(); //Making constructor private or protected makes this class non-instantiable.

	public:

		static void convert(std::string str);
};