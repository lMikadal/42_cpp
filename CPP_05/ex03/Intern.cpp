#include "Intern.hpp"

Intern::Intern() {
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &rhs) {
	*this = rhs;
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern::~Intern() {
	std::cout << "Intern destructor called" << std::endl;
}

Intern&	Intern::operator=(const Intern &rhs) {
	return (*this = rhs);
}

AForm*	Intern::makeForm(const std::string &name, const std::string &target) {
	AForm*	form;

	try {
		if (name == "robotomy request")
			form = new RobotomyRequestForm(target);
		else if (name == "presidential pardon")
			form = new PresidentialPardonForm(target);
		else if (name == "shrubbery creation")
			form = new ShrubberyCreationForm(target);
		else
			throw Intern::InvalidFormException();

		std::cout << "Intern creates " << form->getName() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return (NULL);
	}
	
	return (form);
}

const char* Intern::InvalidFormException::what() const throw() {
	return ("Invalid form name please choose:\n- robotomy request\n- presidential pardon\n- shrubbery creation");
}