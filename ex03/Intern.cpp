#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &copy)
{
	(void)copy;
}

Intern &Intern::operator=(const Intern &rhs)
{
	(void)rhs;
	return (*this);
}

Intern::~Intern()
{
}

AForm* Intern::createPresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm* Intern::createRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::createShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeForm(std::string formName, std::string formTarget)
{
	const char *formNames[3] = {
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"
	};

	AForm* (Intern::*formCreators[3])(std::string) = {
		&Intern::createPresidentialPardonForm,
		&Intern::createRobotomyRequestForm,
		&Intern::createShrubberyCreationForm
	};

	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return ((this->*formCreators[i])(formTarget));
		}
	}

	std::cerr << "Intern can't create " << formName << " because it's an unknown form" << std::endl;
	return (NULL);
}