#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"


int main()
{
	std::cout << RED << "PresidentialPardonForm" << RESET << std::endl;
	PresidentialPardonForm ppf("ppf");
	std::cout << ppf << std::endl;
	Bureaucrat b("b", 1);
	std::cout << b << std::endl;
	ppf.beSigned(b);
	std::cout << ppf << std::endl;
	b.executeForm(ppf);
	std::cout << ppf << std::endl;
	b.executeForm(ppf);
	std::cout << ppf << std::endl;
	std::cout << RED << "RobotomyRequestForm" << RESET << std::endl;
	RobotomyRequestForm rrf("rrf");
	std::cout << rrf << std::endl;
	std::cout << b << std::endl;
	rrf.beSigned(b);
	std::cout << rrf << std::endl;
	b.executeForm(rrf);
	std::cout << rrf << std::endl;
	b.executeForm(rrf);
	std::cout << rrf << std::endl;
	std::cout << RED << "ShrubberyCreationForm" << RESET << std::endl;
	ShrubberyCreationForm scf("scf");
	std::cout << scf << std::endl;
	std::cout << b << std::endl;
	scf.beSigned(b);
	std::cout << scf << std::endl;
	b.executeForm(scf);
	std::cout << scf << std::endl;
	b.executeForm(scf);
	std::cout << scf << std::endl;
	return 0;
}