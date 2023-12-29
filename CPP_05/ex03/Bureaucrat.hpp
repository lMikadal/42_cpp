#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

class AForm;

class Bureaucrat {
	private:
		const std::string	_name;
		int 				_grade;

	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &rhs);
		Bureaucrat(const std::string &name, const int &grade);
		~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat &rhs);

		int			getGrade() const;
		std::string	getName() const;
		void		setGrade(const int &grade);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		void		signForm(AForm &f) const;
		void		executeForm(const AForm &form) const;
};

std::ostream&	operator<<(std::ostream &out, const Bureaucrat &rhs);

#endif