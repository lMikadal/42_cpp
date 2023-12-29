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
		AForm(const AForm &b);
		AForm(const std::string &name, const int &gradeToSign, const int &gradeToExecute);
		AForm(const std::string &name, const int &gradeToSign, const int &gradeToExecute, const std::string &target);
		~AForm();
		AForm& operator=(const AForm &b);

		std::string	getName() const;
		bool		getSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;
		std::string	getTarget() const;
		void		setSigned(const bool &b);

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
		void				execute(const Bureaucrat &grade) const;
		virtual void		action() const = 0;
};

std::ostream& operator<<(std::ostream &out, const AForm &b);

#endif