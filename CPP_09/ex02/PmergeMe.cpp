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

// delete
void print_test(std::vector<int> &v, std::string str = "")
{
	std::cout << str << ": ";
	for (int i = 0; i < (int)v.size(); i++)
		std::cout << v[i] << " ";
	std::cout << std::endl;
}

void PmergeMe::exec()
{
	std::vector<int> begin = this->_v;

	this->v_merge_insert_sort(this->_v);
	this->l_merge_insert_sort(this->_l);

	std::cout << "Before: ";
	for (int i = 0; i < this->_n; i++)
		std::cout << begin[i] << " ";
	std::cout << std::endl;

	std::cout << "After: ";
	for (int i = 0; i < this->_n; i++)
		std::cout << this->_v[i] << " ";
	std::cout << std::endl;
}

void PmergeMe::v_merge_insert_sort(std::vector<int> &v)
{
	if (v.size() <= 2)
		return;

	std::vector<int> left(v.begin(), v.begin() + (v.size() / 2));
	std::vector<int> right(v.begin() + (v.size() / 2), v.end());

	v_merge_insert_sort(left);
	v_merge_insert_sort(right);

	v = this->v_insert_sort(left, right);
}

void PmergeMe::v_insert(std::vector<int> &f, std::vector<int> &tmp)
{
	int i;
	std::vector<int>::iterator b;

	while (f.size() > 0)
	{
		i = 0;
		for (b = tmp.begin(); b < tmp.end(); b++)
		{
			if (tmp[i] > f[0])
			{
				tmp.insert(tmp.begin() + i, f[0]);
				f.erase(f.begin());
				break;
			}
			i++;
		}

		if (i == (int)tmp.size())
		{
			tmp.push_back(f[0]);
			f.erase(f.begin());
		}
	}
}

std::vector<int> PmergeMe::v_insert_sort(std::vector<int> &l, std::vector<int> &r)
{
	std::vector<int> tmp;

	if (l.size() > 0)
	{
		tmp.push_back(l[0]);
		l.erase(l.begin());
	}
	else
	{
		tmp.push_back(r[0]);
		r.erase(r.begin());
	}

	this->v_insert(l, tmp);
	this->v_insert(r, tmp);

	return tmp;
}

void PmergeMe::l_merge_insert_sort(std::list<int> &l)
{
	if (l.size() <= 2)
		return;

	std::list<int> left, right;

	std::list<int>::iterator it = l.begin();
	for (int i = 0; i < (int)(l.size() / 2); i++)
		left.push_back(*it++);
	for (int i = (l.size() / 2); i < (int)l.size(); i++)
		right.push_back(*it++);

	l_merge_insert_sort(left);
	l_merge_insert_sort(right);
}

const char *PmergeMe::ErrorException::what() const throw()
{
	return "Error";
}