#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _name("data.csv") {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &b) : _name(b._name) {}

BitcoinExchange::BitcoinExchange(std::string const &name) : _name(name) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &b)
{
	if (this != &b)
		this->_name = b._name;

	return (*this);
}

std::string BitcoinExchange::getName(void) const
{
	return (this->_name);
}