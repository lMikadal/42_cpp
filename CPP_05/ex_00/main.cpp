#include "Bureaucrat.hpp"

int	main(void) {
	try {
		Bureaucrat test("test", 150);
		std::cout << test;
		// test.setGrade(-1);
		// test.setGrade(151);
		test.setGrade(1);
		std::cout << test;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}