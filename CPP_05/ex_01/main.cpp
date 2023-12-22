#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void) {
	try {
		Bureaucrat b("low test", 150);
		Form f("low form", 150, 150);
		Form f2("high form", 1, 1);

		b.signForm(f2);
		std::cout << f2;
		b.signForm(f);
		std::cout << f;
		
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}