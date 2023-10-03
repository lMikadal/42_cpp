#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat (void) : _name("default"), _grade(150) {
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat (const Bureaucrat &b) : _name(b._name), _grade(b._grade) {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat (void) {
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &b) {
	if (this == &b)
		return (*this);
	_grade = b._grade;
	return (*this);
}