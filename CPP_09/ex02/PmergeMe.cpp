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

void PmergeMe::exec()
{
	std::vector<int> tmp = this->_v;

	this->v_merge_sort(this->_v);
	this->l_merge_sort(this->_l);
}

void PmergeMe::v_merge_sort(std::vector<int> &v)
{
	if (v.size() <= 2)
		return;

	std::vector<int> left(v.begin(), v.begin() + (v.size() / 2));
	std::vector<int> right(v.begin() + (v.size() / 2), v.end());

	v_merge_sort(left);
	v_merge_sort(right);
}

void PmergeMe::l_merge_sort(std::list<int> &l)
{
	if (l.size() <= 2)
		return;

	std::list<int> left;
	std::list<int> right;

	std::list<int>::iterator it = l.begin();
	for (int i = 0; i < (int)(l.size() / 2); i++)
		left.push_back(*it++);
	for (int i = (l.size() / 2); i < (int)l.size(); i++)
		right.push_back(*it++);

	l_merge_sort(left);
	l_merge_sort(right);
}

const char *PmergeMe::InvalidArgvException::what() const throw()
{
	return "Invalid argument";
}