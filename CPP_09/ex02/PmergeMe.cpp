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

void PmergeMe::print_detail(int n, std::string type, double time)
{
	std::cout << "Time to process a range of " << n << " elements with std::" << type << " : " << time << " us" << std::endl;
}

void PmergeMe::exec()
{
	std::vector<int> begin = this->_v;

	clock_t begin_time_v = clock();
	merge_insert_sort(this->_v);
	clock_t begin_time_l = clock();
	merge_insert_sort(this->_l);

	print_list(begin, "Before: ");
	print_list(this->_v, "After:  ");
	print_detail(this->_n, "vector<int>", (double(clock() - begin_time_v) / CLOCKS_PER_SEC) * 1000000);
	print_detail(this->_n, "list<int>  ", (double(clock() - begin_time_l) / CLOCKS_PER_SEC) * 1000000);
}

const char *PmergeMe::ErrorException::what() const throw()
{
	return "Error";
}