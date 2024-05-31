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

	void v_merge_insert_sort(std::vector<int> &v);
	void v_insert(std::vector<int> &f, std::vector<int> &tmp);
	std::vector<int> v_insert_sort(std::vector<int> &l, std::vector<int> &r);
	void l_merge_insert_sort(std::list<int> &l);

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

#endif