#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN
{
private:
	void static cal(char op, std::stack<int> &stack);

public:
	RPN();
	RPN(const RPN &);
	~RPN();
	RPN &operator=(const RPN &);

	int static calculate(std::string str);

	class ErrorException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

#endif