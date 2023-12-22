#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

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

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		void		signForm(class Form &f) const;
};

std::ostream&	operator<<(std::ostream &out, const Bureaucrat &b);

#endif