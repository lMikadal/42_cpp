#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T &a, T &b)
{
	T tmp;

	tmp = b;
	b = a;
	a = tmp;
}

template <typename T>
T min(T const &a, T const &b)
{
	if (a < b)
		return a;
	return b;
}

template <typename T>
T max(T const &a, T const &b)
{
	if (a > b)
		return a;
	return b;
}

#endif
