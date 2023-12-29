#include "Bureaucrat.hpp"
#include "Intern.hpp"

int	main(void) {
	Intern	someRandomIntern;
	AForm*	rrf;
	Bureaucrat	b("Bender", 149);

	rrf = someRandomIntern.makeForm("", "Bender");

	if (rrf) {
		b.signForm(*rrf);
		b.executeForm(*rrf);
		delete rrf;
	}

	return (0);
}