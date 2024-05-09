#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

class Span
{
private:
	unsigned int _N;
	std::vector<int> _v;

public:
	Span();
	Span(const unsigned int &N);
	Span(const Span &s);
	~Span();
	Span &operator=(const Span &s);

	void addNumber(const int &n);
	int shortestSpan(void);
	int longestSpan(void);

	class NoAddDataSpanException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class NotEnoughNumbersException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

#endif
