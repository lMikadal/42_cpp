#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <cstdlib>

template <typename T>
class Array
{
private:
	int *arr;
	unsigned int length;

public:
	Array();
	Array(unsigned int n);
	Array(const Array &other);
	~Array();
	Array &operator=(const Array &other);
	int &operator[](unsigned int i);
	unsigned int size() const;
};

template <typename T>
Array<T>::Array() : arr(NULL), length(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : arr(new int[n]), length(n) {}

template <typename T>
Array<T>::Array(const Array<T> &other) : arr(new int[other.length]), length(other.length)
{
	for (unsigned int i = 0; i < length; i++)
		arr[i] = other.arr[i];
}

template <typename T>
Array<T>::~Array()
{
	delete[] arr;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
	if (this == &other)
		return *this;
	delete[] arr;

	arr = new int[other.length];
	length = other.length;
	for (unsigned int i = 0; i < length; i++)
		arr[i] = other.arr[i];

	return *this;
}

template <typename T>
int &Array<T>::operator[](unsigned int i)
{
	if (i >= length)
		throw std::out_of_range("Index out of range");

	return arr[i];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return length;
}

#endif