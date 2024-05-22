#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>

class BitcoinExchange
{
private:
	std::string _name;

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &);
	BitcoinExchange(std::string const &);
	~BitcoinExchange();
	BitcoinExchange &operator=(const BitcoinExchange &);

	std::string getName(void) const;
};

#endif