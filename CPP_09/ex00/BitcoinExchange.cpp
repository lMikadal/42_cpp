#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _data("data.csv")
{
	this->readFileData();
}

BitcoinExchange::BitcoinExchange(std::string const &name) : _data(name)
{
	this->readFileData();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &b) : _data(b._data), _input(b._input), _dataMap(b._dataMap) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &b)
{
	if (this != &b)
	{
		this->_data = b._data;
		this->_input = b._input;
		this->_dataMap = b._dataMap;
	}

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

void BitcoinExchange::readFileData(void)
{
	std::ifstream file(this->_data.c_str());
	std::string line;
	std::string key;
	double value;

	if (!file.is_open())
		throw BitcoinExchange::InputFileCouldNotOpenException();

	while (std::getline(file, line))
	{
		if (line.find(',') == std::string::npos)
			throw BitcoinExchange::DataFileErrorException();

		key = line.substr(0, line.find(','));
		if (key != "date" && !this->chkFmtKey(key))
			throw BitcoinExchange::DataFileErrorException();

		std::stringstream ss(line.substr(line.find(',') + 1));
		ss >> value;
		this->_dataMap.insert(std::pair<std::string, double>(key, value));
	}

	file.close();
}

bool BitcoinExchange::chkFmtKey(std::string const &key) const
{
	std::stringstream ss(key);
	std::string token;
	int chk = 0;
	int i = 0;

	while (std::getline(ss, token, '-'))
	{
		std::stringstream(token) >> chk;
		if ((i == 0 && (token.size() != 4 || chk < 0)) ||
			(i == 1 && (token.size() != 2 || chk < 1 || chk > 12)) ||
			(i == 2 && (token.size() != 2 || chk < 1 || chk > 31)) ||
			(i == 3))
			return (false);
		i++;
	}

	return (true);
}

const char *BitcoinExchange::InputFileCouldNotOpenException::what() const throw()
{
	return ("could not open file.");
}

const char *BitcoinExchange::DataFileErrorException::what() const throw()
{
	return ("file data.csv error");
}