#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	private:
		ShrubberyCreationForm();

	public:
		ShrubberyCreationForm(const ShrubberyCreationForm &rhs);
		ShrubberyCreationForm(const std::string &target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &rhs);

		void 		action() const;
};

#endif