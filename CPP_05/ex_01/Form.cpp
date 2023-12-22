#include "Form.hpp"

Form::Form(void) : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const Form &b) : _name(b.getName()), _signed(b.getSigned()), _gradeToSign(b.getGradeToSign()), _gradeToExecute(b.getGradeToExecute()) {
	std::cout << "Form copy constructor called" << std::endl;
}

Form::Form(const std::string &name, const int &gradeToSign, const int &gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
	std::cout << "Form constructor called" << std::endl;
}

Form::~Form(void) {
	std::cout << "Form destructor called" << std::endl;
}

Form&	Form::operator=(const Form &b) {
	if(this != &b)
		this->_signed = b.getSigned();

	return (*this);
}

std::string	Form::getName(void) const {
	return (this->_name);
}

bool	Form::getSigned(void) const {
	return (this->_signed);
}

int	Form::getGradeToSign(void) const {
	return (this->_gradeToSign);
}

int	Form::getGradeToExecute(void) const {
	return (this->_gradeToExecute);
}

void	Form::beSigned(const int &grade) {
	if (grade > this->_gradeToSign)
		throw Form::GradeTooLowException();
	else
		this->_signed = true;
}

const char* Form::GradeTooHighException::what() const throw() {
	return ("Form grade too high");
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("Form grade too low");
}

std::ostream&	operator<<(std::ostream &out, const Form &f) {
	out << f.getName() << ", form grade to sign " << f.getGradeToSign() << ", form grade to execute " << f.getGradeToExecute() << ", signed " << f.getSigned() << std::endl;
	return (out);
}