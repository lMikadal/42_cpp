#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _data("data.csv")
{
	this->setFileData();
}

BitcoinExchange::BitcoinExchange(std::string const &name) : _data(name)
{
	this->setFileData();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &b)
{
	*this = b;
}

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

std::string BitcoinExchange::trim(std::string const &str)
{
	std::string word;
	std::stringstream stream(str);
	stream >> word;

	return word;
}

int BitcoinExchange::strToInt(std::string const &str) const
{
	int word;
	std::stringstream stream(str);
	stream >> word;

	return word;
}

std::string BitcoinExchange::intToString(const int &value) const
{
	std::ostringstream oss;
	oss << value;
	return oss.str();
}

double BitcoinExchange::getExchangeRate(std::string const &date) const
{
	std::map<std::string, double>::const_iterator it = this->_dataMap.find(date);
	if (it != this->_dataMap.end())
		return it->second;

	int year = this->strToInt(date.substr(0, 4));
	int month = this->strToInt(date.substr(5, 2));
	int day = this->strToInt(date.substr(8, 2));

	while (year > 0)
	{
		while (month >= 0)
		{
			while (day >= 0)
			{
				std::string sm = this->intToString(month);
				if (sm.size() == 1)
					sm = "0" + sm;
				std::string sd = this->intToString(day);
				if (sd.size() == 1)
					sd = "0" + sd;
				std::string dd = this->intToString(year) + "-" + sm + "-" + sd;
				it = this->_dataMap.find(dd);
				if (it != this->_dataMap.end())
					return it->second;
				day--;
			}
			month--;
			day = 31;
		}
		year--;
		month = 12;
	}

	if (it == this->_dataMap.end())
		throw BitcoinExchange::BadInputException("bad input => " + date);

	return it->second;
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

void BitcoinExchange::setFileData(void)
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

		key = trim(line.substr(0, line.find(',')));
		if (key != "date" && !this->chkFmtDate(key))
			throw BitcoinExchange::DataFileErrorException();

		std::stringstream ss(line.substr(line.find(',') + 1));
		ss >> value;
		this->_dataMap.insert(std::pair<std::string, double>(key, value));
	}

	file.close();
}

void BitcoinExchange::readFileInput(void)
{
	std::ifstream file(this->_input.c_str());
	std::string line;
	std::string date;
	int i = 0;
	double rate, coin;

	if (!file.is_open())
		throw BitcoinExchange::InputFileCouldNotOpenException();

	while (std::getline(file, line))
	{
		i++;
		try
		{
			if (line.find('|') == std::string::npos)
				throw BitcoinExchange::BadInputException("bad input => " + line);

			date = trim(line.substr(0, line.find('|')));
			if (i == 1 && date == "date")
				continue;
			if (date != "date" && !this->chkFmtDate(date))
				throw BitcoinExchange::BadInputException("bad input => " + line);

			std::stringstream ss(line.substr(line.find('|') + 1));
			ss >> coin;
			if (coin < 0)
				throw BitcoinExchange::NotPositiveException();
			else if (coin > 1000)
				throw BitcoinExchange::LargeNumberException();

			rate = this->getExchangeRate(date);
			std::cout << date << " => " << coin << " = " << rate * coin << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}

	file.close();
}

bool BitcoinExchange::chkFmtDate(std::string const &key) const
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

const char *BitcoinExchange::BadInputException::what() const throw()
{
	return this->_msg.c_str();
}

const char *BitcoinExchange::NotPositiveException::what() const throw()
{
	return ("not a positive number.");
}

const char *BitcoinExchange::LargeNumberException::what() const throw()
{
	return ("too large a number.");
}