#pragma once

#include <iomanip>
#include <iostream>

#define GREEN "\033[32m"
#define RESET "\033[0m"
#define BLUE    "\033[34m"
#define PINK "\033[35m"

typedef struct Data
{
	std::string name;
	

}s_Data;

class Serializer
{
	private:
		Serializer();


	public:
		static uintptr_t serialize(Data* ptr); //It takes a pointer and converts it to the unsigned integer type uintptr_t.
		static Data* deserializer(uintptr_t raw); //It takes an unsigned integer parameter and converts it to a pointer to Data.


};