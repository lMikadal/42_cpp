#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
bool easyfind(T &container, int n)
{
	typename T::iterator it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		throw std::exception();
	return true;
}

#endif