#ifndef Form_HPP
# define Form_HPP

# include <iostream>
# include <exception>

class Form {
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public:
		Form();
		Form(const Form &b);
		Form(const std::string &name, const int &gradeToSign, const int &gradeToExecute);
		~Form();
		Form& operator=(const Form &b);

		std::string	getName(void) const;
		bool		getSigned(void) const;
		int			getGradeToSign(void) const;
		int			getGradeToExecute(void) const;

		void		beSigned(const int &grade);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream &out, const Form &b);

#endif