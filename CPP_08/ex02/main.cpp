#include "MutantStack.hpp"

int main(void)
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	mstack.push(111);
	std::cout << "---------------------" << std::endl;
	std::cout << mstack.top() << std::endl;
	std::cout << "---------------------" << std::endl;
	mstack.pop();
	std::cout << "---------------------" << std::endl;
	std::cout << mstack.size() << std::endl;
	std::cout << "---------------------" << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "---------------------" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << "---------------------" << std::endl;
	std::stack<int> s(mstack);
	return 0;
}