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
	std::string trim(std::string const &);
	int strToInt(std::string const &) const;
	std::string intToString(const int &) const;
	double getExchangeRate(std::string const &) const;

public:
	BitcoinExchange();
	BitcoinExchange(std::string const &);
	BitcoinExchange(const BitcoinExchange &);
	~BitcoinExchange();
	BitcoinExchange &operator=(const BitcoinExchange &);

	std::string getFileData(void) const;
	std::string getFileInput(void) const;
	void setInput(std::string const &);
	void setFileData(void);
	void readFileInput(void);
	bool chkFmtDate(std::string const &) const;

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

	class BadInputException : public std::exception
	{
	private:
		std::string _msg;

	public:
		BadInputException(std::string const &err) throw() : _msg(err){};
		virtual ~BadInputException() throw(){};
		virtual const char *what() const throw();
	};

	class NotPositiveException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class LargeNumberException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

#endif