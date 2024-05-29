#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	try
	{
		if (argc == 1)
			throw PmergeMe::InvalidArgvException();

		PmergeMe::chk_arg(argc, argv);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}