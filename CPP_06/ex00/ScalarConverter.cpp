#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &rhs)
{
	*this = rhs;
	std::cout << "Copy constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "Destructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs)
{
	return *this = rhs;
}

void ScalarConverter::convert(char const *str)
{
	std::string s(str);
	std::cout << "char: " << s << std::endl;
}

const char* ScalarConverter::NonDisplayableException::what() const throw()
{
	return ("Non displayable");
}

const char* ScalarConverter::ImpossibleException::what() const throw()
{
	return ("impossible");
}