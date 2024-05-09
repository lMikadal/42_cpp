#include "Span.hpp"

Span::Span() : _N(0) {}

Span::Span(const unsigned int &N) : _N(N) {}

Span::Span(const Span &s)
{
	*this = s;
}

Span::~Span() {}

Span &Span::operator=(const Span &s)
{
	if (this != &s)
	{
		this->_N = s._N;
		this->_v = s._v;
	}

	return (*this);
}

void Span::addNumber(const int &n)
{
	if (this->_v.size() == this->_N)
		throw Span::NoAddDataSpanException();

	this->_v.push_back(n);
}

int Span::shortestSpan(void)
{
	if (this->_v.size() < 2)
		throw Span::NotEnoughNumbersException();

	std::vector<int> v = this->_v;
	std::sort(v.begin(), v.end());
	int min = v[1] - v[0];

	for (unsigned int i = 1; i < v.size() - 1; i++)
	{
		if (v[i + 1] - v[i] < min)
			min = v[i + 1] - v[i];
	}

	return (min);
}

int Span::longestSpan(void)
{
	if (this->_v.size() < 2)
		throw Span::NotEnoughNumbersException();

	std::vector<int> v = this->_v;
	std::sort(v.begin(), v.end());

	return (v[v.size() - 1] - v[0]);
}

const char *Span::NoAddDataSpanException::what() const throw()
{
	return ("Can't add data to Span");
}

const char *Span::NotEnoughNumbersException::what() const throw()
{
	return ("No enough numbers");
}
