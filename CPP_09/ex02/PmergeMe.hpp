#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>

class PmergeMe
{
private:
	int _n;
	std::vector<int> _v;
	std::list<int> _l;

	void v_merge_sort(std::vector<int> &v);
	void l_merge_sort(std::list<int> &l);

public:
	PmergeMe();
	PmergeMe(const PmergeMe &);
	~PmergeMe();
	PmergeMe &operator=(const PmergeMe &);

	void chk_arg(int argc, char **argv);
	void exec();

	class InvalidArgvException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

#endif