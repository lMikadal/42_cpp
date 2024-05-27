#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &rpn)
{
	*this = rpn;
}
RPN::~RPN() {}

RPN &RPN::operator=(const RPN &rpn)
{
	if (this != &rpn)
	{
		this->_stack = rpn._stack;
		this->_first = rpn._first;
		this->_second = rpn._second;
		this->_result = rpn._result;
	}

	return (*this);
}

const char *RPN::ErrorException::what() const throw()
{
	return "Error";
}