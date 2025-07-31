
#include "MutantStack.hpp"
#include <iostream>

int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << GREEN << "After push(17): " << mstack.top() << RESET << std::endl;

	mstack.pop();

	std::cout << PINK << "mstack Size: " << mstack.size() << RESET << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	mstack.pop();

	std::cout << GREEN << "After push(737), push(0) and pop(): " << mstack.top() << RESET << std::endl;

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
	return 0;
}