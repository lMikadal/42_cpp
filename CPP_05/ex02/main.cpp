#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void) {
	Bureaucrat	bob("Bob", 1);

	ShrubberyCreationForm	formS("test_S");
	bob.signForm(formS);
	bob.executeForm(formS);

	RobotomyRequestForm	formR("test_R");
	bob.signForm(formR);
	bob.executeForm(formR);

	return (0);
}