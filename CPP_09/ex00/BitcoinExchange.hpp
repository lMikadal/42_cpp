#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>

class BitcoinExchange
{
private:
	std::string _data;
	std::string _input;
	std::map<std::string, double> _dataMap;

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &);
	BitcoinExchange(std::string const &);
	~BitcoinExchange();
	BitcoinExchange &operator=(const BitcoinExchange &);

	std::string getFileData(void) const;
	std::string getFileInput(void) const;
	void setInput(std::string const &input);

	class InputFileCouldNotOpenException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class DataFileErrorException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

#endif