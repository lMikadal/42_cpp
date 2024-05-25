#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

class BitcoinExchange
{
private:
	std::string _data;
	std::string _input;
	std::map<std::string, double> _dataMap;

public:
	BitcoinExchange();
	BitcoinExchange(std::string const &);
	BitcoinExchange(const BitcoinExchange &);
	~BitcoinExchange();
	BitcoinExchange &operator=(const BitcoinExchange &);

	std::string getFileData(void) const;
	std::string getFileInput(void) const;
	void setInput(std::string const &input);
	void readFileData(void);

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