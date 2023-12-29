#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		PresidentialPardonForm();

	public:
		PresidentialPardonForm(const PresidentialPardonForm &rhs);
		PresidentialPardonForm(const std::string &target);
		~PresidentialPardonForm();
		PresidentialPardonForm& operator=(const PresidentialPardonForm &rhs);

		void 		action() const;
};

#endif