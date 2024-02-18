#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cstdio>
# include <string>
# include <cstdlib>

class ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &rhs);
		~ScalarConverter();
		ScalarConverter &operator=(ScalarConverter const &rhs);

		static void convert(char const *str);

		class NonDisplayableException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class ImpossibleException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

#endif
