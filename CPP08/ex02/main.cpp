
#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	std::cout << BLUE << "------------------------MUTANT STACK------------------------" << RESET << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

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

	std::cout << BLUE << "-------------------------STD::LIST--------------------------" << RESET << std::endl;
	std::list<int> mlist;

	mlist.push_back(5);
	mlist.push_back(17);

	std::cout << mlist.back() << std::endl;

	mlist.pop_back();

	std::cout << mlist.size() << std::endl;

	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);
	//[...]
	mlist.push_back(0);

	std::list<int>::iterator it_list = mlist.begin();
	std::list<int>::iterator ite_list = mlist.end();

	++it_list;
	--it_list;
	while (it_list != ite_list)
	{
	std::cout << *it_list << std::endl;
	++it_list;
	}

	std::cout << PINK << "*** *** *** *** *** *** *** *** *** *** *** *** *** *** ***" << RESET << std::endl;
	std::cout << BLUE << "---------------------REVERSE ITERATOR-----------------------" << RESET << std::endl;
	MutantStack<int>::reverse_iterator revit = mstack.rbegin();
	MutantStack<int>::reverse_iterator revite = mstack.rend();
	while(revit != revite){
		std::cout << *revit << std::endl;
		++revit;
	}
	std::cout << BLUE << "-----------------------CONST ITERATOR-----------------------" << RESET << std::endl;
	const MutantStack<int> const_mstack = mstack;
	MutantStack<int>::const_iterator cit = const_mstack.cbegin();
	MutantStack<int>::const_iterator cite = const_mstack.cend();
	while(cit != cite){
		std::cout << *cit << std::endl;
		++cit;
	}
	std::cout << BLUE << "------------------CONST REVERSE ITERATOR--------------------" << RESET << std::endl;
	MutantStack<int>::const_reverse_iterator crevit = const_mstack.crbegin();
	MutantStack<int>::const_reverse_iterator crevite = const_mstack.crend();
	while(crevit != crevite){
		std::cout << *crevit << std::endl;
		++crevit;
	}

	return 0;
}