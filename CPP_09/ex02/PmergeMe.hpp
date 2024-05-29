#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>

class PmergeMe
{
public:
	PmergeMe();
	PmergeMe(const PmergeMe &);
	~PmergeMe();
	PmergeMe &operator=(const PmergeMe &);

	void static chk_arg(int argc, char **argv);

	class InvalidArgvException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

#endif