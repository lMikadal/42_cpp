#include "Bureaucrat.hpp"

int	main( void ) {
	try 
	{
		int name = 100;
		throw (name);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}