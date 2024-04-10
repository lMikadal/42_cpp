#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
void iter(T *arr, int len, void (*f)(T &))
{
	for (int i = 0; i < len; i++)
		f(arr[i]);
}

#endif