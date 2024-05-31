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
	int tmp;
	std::string str;

	while (++i < argc)
	{
		std::stringstream ss_str(argv[i]);
		ss_str >> str;
		for (int j = 0; j < (int)str.length(); j++)
		{
			if (!isdigit(argv[i][j]))
				throw ErrorException();
		}
		std::stringstream ss(argv[i]);
		ss >> tmp;

		this->_v.push_back(tmp);
		this->_l.push_back(tmp);
	}

	this->_n = argc - 1;
}

void PmergeMe::exec()
{
	std::vector<int> begin = this->_v;

	merge_insert_sort(this->_v);
	merge_insert_sort(this->_l);

	std::cout << "Before: ";
	for (int i = 0; i < this->_n; i++)
		std::cout << begin[i] << " ";
	std::cout << std::endl;

	std::cout << "After vector: ";
	for (int i = 0; i < this->_n; i++)
		std::cout << this->_v[i] << " ";
	std::cout << std::endl;

	std::cout << "After list: ";
	for (std::list<int>::iterator it = this->_l.begin(); it != this->_l.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

const char *PmergeMe::ErrorException::what() const throw()
{
	return "Error";
}