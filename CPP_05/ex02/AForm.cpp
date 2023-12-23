#include "AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const AForm &b) : _name(b.getName()), _signed(b.getSigned()), _gradeToSign(b.getGradeToSign()), _gradeToExecute(b.getGradeToExecute()) {
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm::AForm(const std::string &name, const int &gradeToSign, const int &gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	std::cout << "AForm constructor called" << std::endl;
}

AForm::~AForm() {
	std::cout << "AForm destructor called" << std::endl;
}

AForm&	AForm::operator=(const AForm &b) {
	if(this != &b)
		this->_signed = b.getSigned();

	return (*this);
}

std::string AForm::getName() const {
	return (this->_name);
}

bool	AForm::getSigned() const {
	return (this->_signed);
}

int	AForm::getGradeToSign() const {
	return (this->_gradeToSign);
}

int	AForm::getGradeToExecute() const {
	return (this->_gradeToExecute);
}

const char* AForm::GradeTooHighException::what() const throw() {
	return ("Grade too high");
}

const char* AForm::GradeTooLowException::what() const throw() {
	return ("Grade too low");
}

std::ostream& operator<<(std::ostream &out, const AForm &f) {
	out << f.getName() << ", form grade to sign " << f.getGradeToSign() << ", form grade to execute " << f.getGradeToExecute() << ", signed " << f.getSigned() << std::endl;
	return (out);
}

void	AForm::beSigned(const int &grade) {
	if (grade > this->_gradeToSign)
		throw AForm::GradeTooLowException();
	else
		this->_signed = true;
}