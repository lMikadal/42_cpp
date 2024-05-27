#include "RPN.hpp"

int main(int argc, char **argv)
{
	(void)argv;
	try
	{
		if (argc != 2)
			throw RPN::ErrorException();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}