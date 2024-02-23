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
	(void)rhs;
	return *this;
}

void chkNanInf(std::string s)
{
	if (s == "-inff" || s == "+inff" || s == "nanf" || s == "-inf" || s == "+inf" || s == "nan")
	{
		throw ScalarConverter::ImpossibleException();
	}
}

std::string chkNanInfForInt(std::string s)
{
	if (s == "-inff" || s == "-inf")
		return "-inf";
	if (s == "+inff" || s == "+inf")
		return "+inf";
	if (s == "nanf" || s == "nan")
		return "nan";
	return "";
}

void convertToChar(double const con_d, std::string s)
{
	std::cout << "char: ";
	try
	{
		chkNanInf(s);
		if (con_d >= 0 && con_d <= 127 && (con_d < 32 || con_d > 126))
			throw ScalarConverter::NonDisplayableException();
		if (con_d < 0 || con_d > 127)
			throw ScalarConverter::ImpossibleException();
		std::cout << "'" << static_cast<char>(con_d) << "'" << std::endl;
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

void convertToInt(double const con_d, std::string s)
{
	std::cout << "int: ";
	try
	{
		chkNanInf(s);
		if (con_d < INT_MIN || con_d > INT_MAX)
			throw ScalarConverter::ImpossibleException();
		std::cout << static_cast<int>(con_d) << std::endl;
	}
	catch (ScalarConverter::ImpossibleException &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void convertToFloat(const double con_d, std::string s)
{
	std::string n_s = chkNanInfForInt(s);
	std::cout << "float: ";

	if (n_s.length() > 0)
	{
		std::cout << n_s << "f" << std::endl;
		return;
	}
	float f = static_cast<float>(con_d);
	int i = static_cast<int>(con_d);
	if (f == i)
		std::cout << i << ".0f" << std::endl;
	else
		std::cout << static_cast<float>(con_d) << "f" << std::endl;
}

void convertToDouble(const double con_d, std::string s)
{
	std::string n_s = chkNanInfForInt(s);
	std::cout << "double: ";

	if (n_s.length() > 0)
	{
		std::cout << n_s << std::endl;
		return;
	}
	int i = static_cast<int>(con_d);
	if (con_d == i)
		std::cout << con_d << ".0" << std::endl;
	else
		std::cout << con_d << std::endl;
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

	convertToChar(con_d, s);
	convertToInt(con_d, s);
	convertToFloat(con_d, s);
	convertToDouble(con_d, s);
}

const char *ScalarConverter::NonDisplayableException::what() const throw()
{
	return ("Non displayable");
}

const char *ScalarConverter::ImpossibleException::what() const throw()
{
	return ("impossible");
}