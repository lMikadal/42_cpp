#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN
{
private:
	std::stack<int> _stack;
	int _first, _second, _result;

public:
	RPN();
	RPN(const RPN &);
	~RPN();
	RPN &operator=(const RPN &);

	class ErrorException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

#endif