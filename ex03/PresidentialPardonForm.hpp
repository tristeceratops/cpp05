#pragma once

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string	_target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &copy);

		~PresidentialPardonForm();

		PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);

		std::string getTarget() const;

		void execute(Bureaucrat const &executor) const;
};