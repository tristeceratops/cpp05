#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("noname"), grade(151){}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade){}

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
}

void Bureaucrat::downgrade()
{
	if (this->grade < 150)
		this->grade++;
}