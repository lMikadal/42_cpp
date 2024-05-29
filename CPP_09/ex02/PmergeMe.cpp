#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &pmergeMe)
{
	*this = pmergeMe;
}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &pmergeMe)
{
	if (this != &pmergeMe)
	{
		this->_n = pmergeMe._n;
		this->_v = pmergeMe._v;
		this->_l = pmergeMe._l;
	}

	return (*this);
}

void PmergeMe::chk_arg(int argc, char **argv)
{
	int i = 0;

	while (++i < argc)
	{
		if (isdigit(*argv[i]))
		{
			this->_v.push_back(*argv[i] - '0');
			this->_l.push_back(*argv[i] - '0');
		}
		else
			throw InvalidArgvException();
	}

	this->_n = argc - 1;
}

const char *PmergeMe::InvalidArgvException::what() const throw()
{
	return "Invalid argument";
}