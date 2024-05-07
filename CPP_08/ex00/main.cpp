#include "easyfind.hpp"

int main(void)
{
	std::vector<int> v;

	for (int i = 0; i < 5; i++)
		v.push_back(i);

	try
	{
		std::cout << easyfind(v, 3) << std::endl;
		std::cout << easyfind(v, 6) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Element not found" << std::endl;
	}
	return 0;
}