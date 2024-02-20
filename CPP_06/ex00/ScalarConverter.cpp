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

void convertToChar(double const con_d)
{
	(void)con_d;
	std::cout << "char: ";
	try
	{
		throw ScalarConverter::ImpossibleException();
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

void convertToInt(double const con_d)
{
	std::cout << "int: " << con_d << std::endl;
}

void convertToFloat(const double con_d)
{
	std::cout << "float: " << con_d << "f" << std::endl;
}

void convertToDouble(const double con_d)
{
	std::cout << "double: " << con_d << std::endl;
}

void ScalarConverter::convert(char const *str)
{
	std::string s(str);
	if (s != "-inff" && s != "+inff" && s != "nanf" && s != "-inf" && s != "+inf" && s != "nan")
	{
		// check string before covert
		int chk_dot = 0;
		for (size_t i = 0; str[i] != '\0'; i++)
		{
			if ((i == 0 && (str[i] == '-' || str[i] == '+')) || str[i] == '.' || (str[i] == 'f' && str[i + 1] == '\0'))
			{
				if (str[i] == '.')
					chk_dot++;
				continue;
			}
			if (!std::isdigit(str[i]) || chk_dot > 1)
			{
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				std::cout << "float: impossible" << std::endl;
				std::cout << "double: impossible" << std::endl;
				return;
			}
		}
	}
	double con_d = std::atof(str);

	convertToChar(con_d);
	convertToInt(con_d);
	convertToFloat(con_d);
	convertToDouble(con_d);
}

const char *ScalarConverter::NonDisplayableException::what() const throw()
{
	return ("Non displayable");
}

const char *ScalarConverter::ImpossibleException::what() const throw()
{
	return ("impossible");
}