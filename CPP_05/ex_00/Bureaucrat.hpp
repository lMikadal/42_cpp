#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat {
	private:
		const std::string	_name;
		int 				_grade;

	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &b);
		Bureaucrat(const std::string &name, const int &grade);
		~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat &b);

		int			getGrade(void) const;
		std::string	getName(void) const;

		void		setGrade(const int &grade);
};

#endif