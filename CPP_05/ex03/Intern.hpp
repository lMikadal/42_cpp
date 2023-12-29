#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <exception>
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"

class AForm;
class RobotomyRequestForm;
class PresidentialPardonForm;
class ShrubberyCreationForm;

class Intern {
	public:
		Intern();
		Intern(const Intern &rhs);
		~Intern();
		Intern&	operator=(const Intern &rhs);

		AForm*	makeForm(const std::string &name, const std::string &target);

		class InvalidFormException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

#endif