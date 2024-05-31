#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	try
	{
		if (argc == 1)
			throw PmergeMe::ErrorException();

		PmergeMe pmergeMe;

		pmergeMe.chk_arg(argc, argv);
		pmergeMe.exec();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}