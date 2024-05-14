#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack() : std::stack<T>() {}
	MutantStack(const MutantStack &m) : std::stack<T>(m) {}
	~MutantStack() {}
	MutantStack &operator=(const MutantStack &m)
	{
		std::stack<T>::operator=(m);
		return *this;
	}

	typedef typename std::deque<T>::iterator iterator;

	iterator begin(void)
	{
		return std::stack<T>::c.begin();
	}

	iterator end(void)
	{
		return std::stack<T>::c.end();
	}
};

#endif