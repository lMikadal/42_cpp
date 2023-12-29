#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("default", 145, 137) {
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &b) : AForm(b.getName(), b.getGradeToSign(), b.getGradeToExecute(), b.getTarget()) {
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137, target) {
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm &b) {
	if (this != &b)
		this->setSigned(b.getSigned());

	return (*this);
}

void	ShrubberyCreationForm::action() const {
	std::string target = this->getTarget() + "_shrubbery";
	std::ofstream f(target.c_str());

	f << "      /\\\n";
	f << "     /\\*\\\n";
	f << "    /\\O\\*\\\n";
	f << "   /*/\\/\\/\\\n";
	f << "  /\\O\\/\\*\\/\\\n";
	f << " /\\*\\/\\*\\/\\/\\\n";
	f << "/\\O\\/\\/*/\\/O/\\\n";
	f << "      ||\n";
	f << "      ||\n";
	f << "      ||\n";
	f << std::endl;
	f << "      /\\\n";
	f << "     /\\*\\\n";
	f << "    /\\O\\*\\\n";
	f << "   /*/\\/\\/\\\n";
	f << "  /\\O\\/\\*\\/\\\n";
	f << " /\\*\\/\\*\\/\\/\\\n";
	f << "/\\O\\/\\/*/\\/O/\\\n";
	f << "      ||\n";
	f << "      ||\n";
	f << "      ||\n";

	f.close();
}