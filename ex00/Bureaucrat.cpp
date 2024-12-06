#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException = "GradeTooHighException";
const char* Bureaucrat::GradeTooLowException = "GradeTooLowException";

Bureaucrat::Bureaucrat() : _name("noname"), _grade(150){}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooLowException;
	else if (grade > 150)
		throw Bureaucrat::GradeTooHighException;
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy.getName()), _grade(copy.getGrade()){}

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &rhs)
{
	if (this != &rhs)
	{
		this->_grade = rhs.getGrade();
	}
	return *this;
}

std::string Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

void Bureaucrat::upgrade()
{
	if (this->_grade > 1)
		this->_grade--;
	else
		throw Bureaucrat::GradeTooLowException;
}

void Bureaucrat::downgrade()
{
	if (this->_grade < 150)
		this->_grade++;
	else
		throw Bureaucrat::GradeTooHighException;
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat &rhs)
{
	out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return out;
}