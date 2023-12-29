#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>

class Bureaucrat;

class AForm {
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public:
		AForm();
		AForm(const AForm &b);
		AForm(const std::string &name, const int &gradeToSign, const int &gradeToExecute);
		~AForm();
		AForm& operator=(const AForm &b);

		std::string	getName() const;
		bool		getSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class FormNotSignedException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		void		beSigned(const int &grade);
		void		execute(const Bureaucrat &grade) const;
};

std::ostream& operator<<(std::ostream &out, const AForm &b);

#endif