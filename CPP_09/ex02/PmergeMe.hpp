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

public:
	PmergeMe();
	PmergeMe(const PmergeMe &);
	~PmergeMe();
	PmergeMe &operator=(const PmergeMe &);

	void chk_arg(int argc, char **argv);

	class InvalidArgvException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

#endif