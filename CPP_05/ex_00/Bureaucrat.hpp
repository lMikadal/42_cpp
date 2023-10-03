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
		Bureaucrat (const std::string name, int grade);
		~Bureaucrat ();
		Bureaucrat& operator=(const Bureaucrat &b);

		std::string	getName (void) const;
		int	getGrade (void) const;

		void	setGrade (const int grade);
};

#endif