#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat {
	private:
		const std::string	_name;
		int 				_grade;

	public:
		Bureaucrat ();
		Bureaucrat (const Bureaucrat &b);
		~Bureaucrat ();
		Bureaucrat& operator=(const Bureaucrat &b);
};

#endif