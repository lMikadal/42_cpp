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
	std::cout << "convert called with " << str << std::endl;
}