#include "Base.hpp"
#include "ClassA.hpp"
#include "ClassB.hpp"
#include "ClassC.hpp"
#include <random>
#include <functional>
#include <vector>
#include <memory>
#include <iostream>

#define GREEN "\033[32m"
#define RESET "\033[0m"
#define BLUE "\033[34m"
#define PINK "\033[35m"
#define YELLOW "\033[33m"
#define RED "\033[31m"

Base* generate(void)
{
	static  std::random_device rd; //seed generator
	static 	std::mt19937 gen(rd()); //Mersenne Twister random number generator.

	static const std::vector<std::function<Base*()>> factories = {
		[]() { return new ClassA(); },
		[]() { return new ClassB(); },
		[]() { return new ClassC(); }
	};

	std::uniform_int_distribution<> dist(0, factories.size() - 1);
	return factories[dist(gen)]();
}


void identify(Base* p)
{
	//Not need for try and catch blocks because dynamic_cast returns nullptr on pointer fail.
	if (dynamic_cast<ClassA*>(p))
		std::cout << PINK "Class A - pointer" RESET << std::endl;
	else if (dynamic_cast<ClassB*>(p))
		std::cout << BLUE "Class B - pointer" RESET << std::endl;
	else if (dynamic_cast<ClassC*>(p))
		std::cout << YELLOW "Class C - pointer" RESET << std::endl;
	else
		std::cout << RED "No pointer match." RESET << std::endl;
}

void identify(Base& p)
{
	//We need try and catch blocks because dynamic_cast on a reference throws a std::bad_cast exception if the cast fails.
	try {
		(void)dynamic_cast<ClassA&>(p);
		std::cout << PINK "Class A - reference" RESET << std::endl;
		return;
	} catch (const std::bad_cast&) {}

	try {
		(void)dynamic_cast<ClassB&>(p);
		std::cout << BLUE "Class B - reference" RESET << std::endl;
		return;
	} catch (const std::bad_cast&) {}

	try {
		(void)dynamic_cast<ClassC&>(p);
		std::cout << YELLOW "Class C - reference" RESET << std::endl;
		return;
	} catch (const std::bad_cast&) {}

	std::cout << RED "No pointer match." RESET << std::endl;
}

int main()
{
	Base* base = nullptr;
	identify(base);
	identify(*base);

	Base* randomClass = generate();
	identify(randomClass);
	identify(*randomClass);
	delete randomClass;

	return (0);
}

