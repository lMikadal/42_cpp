#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &rpn)
{
	*this = rpn;
}
RPN::~RPN() {}

RPN &RPN::operator=(const RPN &rpn)
{
	(void)rpn;
	return (*this);
}

void RPN::cal(char op, std::stack<int> &stack)
{
	int _result, _first, _second;

	if (stack.size() < 2)
		throw ErrorException();

	_second = stack.top();
	stack.pop();
	_first = stack.top();
	stack.pop();

	if (op == '+')
		_result = _first + _second;
	else if (op == '-')
		_result = _first - _second;
	else if (op == '*')
		_result = _first * _second;
	else if (op == '/')
	{
		if (_second == 0)
			throw ErrorException();
		_result = _first / _second;
	}

	stack.push(_result);
}

int RPN::calculate(std::string str)
{
	std::stack<int> stack;
	std::string::iterator it = str.begin();

	while (it != str.end())
	{
		if (*it == ' ')
			;
		else if (isdigit(*it))
			stack.push(*it - '0');
		else if (*it == '+')
			cal('+', stack);
		else if (*it == '-')
			cal('-', stack);
		else if (*it == '*')
			cal('*', stack);
		else if (*it == '/')
			cal('/', stack);
		else
			throw ErrorException();

		it++;
	}

	if (stack.size() != 1)
		throw ErrorException();

	return stack.top();
}

const char *RPN::ErrorException::what() const throw()
{
	return "Error";
}