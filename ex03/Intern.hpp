#pragma once

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	private:
		AForm *createPresidentialPardonForm(std::string target);
		AForm *createRobotomyRequestForm(std::string target);
		AForm *createShrubberyCreationForm(std::string target);
	public:
		Intern();
		Intern(const Intern &copy);

		Intern &operator=(const Intern &rhs);

		~Intern();

		AForm *makeForm(std::string formName, std::string formTarget);
};