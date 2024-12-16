#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"


#define RESET   "\033[0m"
#define RED     "\033[31m"


int main()
{
	//test intern
	Intern intern;

	AForm *form1 = intern.makeForm("presidential pardon", "target1");
	AForm *form2 = intern.makeForm("robotomy request", "target2");
	AForm *form3 = intern.makeForm("shrubbery creation", "target3");
	AForm *form4 = intern.makeForm("unknown form", "target4");

	std::cout << "form1: " << form1 << std::endl;
	std::cout << "form2: " << form2 << std::endl;
	std::cout << "form3: " << form3 << std::endl;
	std::cout << "form4: " << form4 << std::endl;

	std::cout << "form1: " << *form1 << std::endl;
	std::cout << "form2: " << *form2 << std::endl;
	std::cout << "form3: " << *form3 << std::endl;

	delete form1;
	delete form2;
	delete form3;
	delete form4;

	return 0;
}