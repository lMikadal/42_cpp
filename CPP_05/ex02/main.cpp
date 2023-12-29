#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void) {
	Bureaucrat	bob("Bob", 1);

	ShrubberyCreationForm	form("home");
	bob.signForm(form);
	bob.executeForm(form);

	return (0);
}