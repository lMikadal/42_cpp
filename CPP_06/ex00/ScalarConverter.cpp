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

void convertToChar(char const *str, double const convD)
{
	(void)str;
	(void)convD;
	std::cout << "char: ";
	try
	{
		throw ScalarConverter::ImpossibleException();
		throw ScalarConverter::NonDisplayableException();
		std::cout << str << std::endl;
	}
	catch (ScalarConverter::NonDisplayableException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (ScalarConverter::ImpossibleException &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void convertToInt(char const *str, double const convD)
{
	(void)str;
	std::cout << "int: " << convD << std::endl;
}

void convertToFloat(char const *str, const double convD)
{
	(void)str;
	std::cout << "float: " << convD << "f" << std::endl;
}

void convertToDouble(char const *str, const double convD)
{
	(void)str;
	std::cout << "double: " << convD << std::endl;
}

void ScalarConverter::convert(char const *str)
{
	double convD = std::atof(str);

	convertToChar(str, convD);
	convertToInt(str, convD);
	convertToFloat(str, convD);
	convertToDouble(str, convD);
}

const char *ScalarConverter::NonDisplayableException::what() const throw()
{
	return ("Non displayable");
}

const char *ScalarConverter::ImpossibleException::what() const throw()
{
	return ("impossible");
}