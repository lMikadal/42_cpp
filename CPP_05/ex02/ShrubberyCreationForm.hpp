#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	private:
		std::string				_target;
		
		ShrubberyCreationForm();

	public:
		ShrubberyCreationForm(const ShrubberyCreationForm &b);
		ShrubberyCreationForm(const std::string &target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &b);

		std::string	getTarget() const;
		void 		action() const;
};

#endif