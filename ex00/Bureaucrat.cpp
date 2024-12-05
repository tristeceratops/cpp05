#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException = "GradeTooHighException";
const char* Bureaucrat::GradeTooLowException = "GradeTooLowException";

Bureaucrat::Bureaucrat() : name("noname"), grade(150){}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooLowException;
	else if (grade > 150)
		throw Bureaucrat::GradeTooHighException;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name(copy.getName()), grade(copy.getGrade()){}

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &rhs)
{
	if (this != &rhs)
	{
		this->grade = rhs.getGrade();
	}
	return *this;
}

std::string Bureaucrat::getName() const
{
	return this->name;
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}

void Bureaucrat::upgrade()
{
	if (this->grade > 1)
		this->grade--;
	else
		throw Bureaucrat::GradeTooLowException;
}

void Bureaucrat::downgrade()
{
	if (this->grade < 150)
		this->grade++;
	else
		throw Bureaucrat::GradeTooHighException;
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat &rhs)
{
	out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return out;
}