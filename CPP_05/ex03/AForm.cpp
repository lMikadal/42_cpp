#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150), _target("default") {
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const AForm &rhs) : _name(rhs.getName()), _signed(rhs.getSigned()), _gradeToSign(rhs.getGradeToSign()), _gradeToExecute(rhs.getGradeToExecute()), _target(rhs.getTarget()) {
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm::AForm(const std::string &name, const int &gradeToSign, const int &gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _target("default") {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	std::cout << "AForm constructor called" << std::endl;
}

AForm::AForm(const std::string &name, const int &gradeToSign, const int &gradeToExecute, const std::string &target) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _target(target) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	std::cout << "AForm constructor called" << std::endl;
}

AForm::~AForm() {
	std::cout << "AForm destructor called" << std::endl;
}

AForm&	AForm::operator=(const AForm &rhs) {
	if(this != &rhs)
		this->_signed = rhs.getSigned();

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

std::string AForm::getTarget() const {
	return (this->_target);
}

void AForm::setSigned(const bool &sign) {
	this->_signed = sign;
}

const char* AForm::GradeTooHighException::what() const throw() {
	return ("Grade too high");
}

const char* AForm::GradeTooLowException::what() const throw() {
	return ("Grade too low");
}

const char* AForm::FormNotSignedException::what() const throw() {
	return ("Form not signed");
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

void AForm::execute(const Bureaucrat &executor) const {
	if (executor.getGrade() > this->_gradeToExecute)
		throw AForm::GradeTooLowException();
	else if (!this->_signed)
		throw AForm::FormNotSignedException();
	else
		this->action();
}