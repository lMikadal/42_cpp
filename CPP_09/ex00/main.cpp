#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw BitcoinExchange::InputFileCouldNotOpenException();

		BitcoinExchange exchange("data.csv");
		exchange.setInput(argv[1]);

		std::cout << "Data file: " << exchange.getFileData() << std::endl;
		std::cout << "Input file: " << exchange.getFileInput() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}