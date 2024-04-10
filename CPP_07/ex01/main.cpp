#include "iter.hpp"

void printInt(int &i)
{
	std::cout << "type int:" << std::endl;
	std::cout << i << std::endl;
}

void printChar(char &c)
{
	std::cout << "type char:" << std::endl;
	std::cout << c << std::endl;
}

template <typename T>
void print(T &t)
{
	std::cout << "type T:" << std::endl;
	std::cout << t << std::endl;
}

int main(void)
{
	int arrInt[5] = {1, 2, 3, 4, 5};
	::iter(arrInt, 5, printInt);
	::iter(arrInt, 5, print);

	char arrChar[5] = {'a', 'b', 'c', 'd', 'e'};
	::iter(arrChar, 5, printChar);
	::iter(arrChar, 5, print);

	return 0;
}
