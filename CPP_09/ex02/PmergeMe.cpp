#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &pmergeMe)
{
	*this = pmergeMe;
}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &pmergeMe)
{
	(void)pmergeMe;
	return (*this);
}

void PmergeMe::chk_arg(int argc, char **argv)
{
	int i = 0;

	while (++i < argc)
	{
		if (isdigit(*argv[i]))
			std::cout << *argv[i] - '0' << std::endl;
		else
			throw InvalidArgvException();
	}
}

const char *PmergeMe::InvalidArgvException::what() const throw()
{
	return "Invalid argument";
}