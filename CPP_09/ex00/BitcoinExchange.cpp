#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _data("data.csv") {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &b) : _data(b._data) {}

BitcoinExchange::BitcoinExchange(std::string const &name) : _data(name) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &b)
{
	if (this != &b)
		this->_data = b._data;

	return (*this);
}

std::string BitcoinExchange::getFileData(void) const
{
	return (this->_data);
}

std::string BitcoinExchange::getFileInput(void) const
{
	return (this->_input);
}

void BitcoinExchange::setInput(std::string const &input)
{
	this->_input = input;
}

const char *BitcoinExchange::InputFileCouldNotOpenException::what() const throw()
{
	return ("could not open file.");
}

const char *BitcoinExchange::DataFileErrorException::what() const throw()
{
	return ("file data.csv error");
}