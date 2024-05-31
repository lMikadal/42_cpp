#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <list>

class PmergeMe
{
private:
	int _n;
	std::vector<int> _v;
	std::list<int> _l;

public:
	PmergeMe();
	PmergeMe(const PmergeMe &);
	~PmergeMe();
	PmergeMe &operator=(const PmergeMe &);

	void chk_arg(int argc, char **argv);
	void exec();

	class ErrorException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

template <typename T>
void insert(T &f, T &tmp)
{
	int i;

	while (f.size() > 0)
	{
		i = 0;
		for (typename T::iterator it = tmp.begin(); it != tmp.end(); it++)
		{
			if (*it > f.front())
			{
				tmp.insert(it, f.front());
				f.erase(f.begin());
				break;
			}
			i++;
		}

		if (i == (int)tmp.size())
		{
			tmp.push_back(f.front());
			f.erase(f.begin());
		}
	}
}

template <typename T>
T insert_sort(T &l, T &r)
{
	T tmp;

	if (l.size() > 0)
	{
		tmp.push_back(l.front());
		l.erase(l.begin());
	}
	else
	{
		tmp.push_back(r.front());
		r.erase(r.begin());
	}

	insert(l, tmp);
	insert(r, tmp);

	return tmp;
}

template <typename T>
void merge_insert_sort(T &data)
{
	if (data.size() <= 2)
		return;

	T left, right;
	typename T::iterator it = data.begin();

	for (int i = 0; i < (int)(data.size() / 2); i++)
		left.push_back(*it++);
	for (int i = (data.size() / 2); i < (int)data.size(); i++)
		right.push_back(*it++);

	merge_insert_sort(left);
	merge_insert_sort(right);

	data = insert_sort(left, right);
}

#endif