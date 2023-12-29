#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <fstream>

class Bureaucrat;

class AForm {
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;
		const std::string	_target;

	public:
		AForm();
		AForm(const AForm &rhs);
		AForm(const std::string &name, const int &gradeToSign, const int &gradeToExecute);
		AForm(const std::string &name, const int &gradeToSign, const int &gradeToExecute, const std::string &target);
		~AForm();
		AForm& operator=(const AForm &rhs);

		std::string	getName() const;
		bool		getSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;
		std::string	getTarget() const;
		void		setSigned(const bool &sign);

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

		void				beSigned(const int &grade);
		void				execute(const Bureaucrat &executor) const;
		virtual void		action() const = 0;
};

std::ostream& operator<<(std::ostream &out, const AForm &f);

#endif