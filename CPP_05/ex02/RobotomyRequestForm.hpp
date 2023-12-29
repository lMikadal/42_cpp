#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib>
# include <ctime>

class RobotomyRequestForm : public AForm {
	private:
		RobotomyRequestForm();

	public:
		RobotomyRequestForm(const RobotomyRequestForm &b);
		RobotomyRequestForm(const std::string &target);
		~RobotomyRequestForm();
		RobotomyRequestForm& operator=(const RobotomyRequestForm &b);

		void 		action() const;
};

#endif