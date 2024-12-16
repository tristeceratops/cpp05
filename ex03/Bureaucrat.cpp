#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat() : _name("noname"), _grade(150){}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooLowException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooHighException();
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
		throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::downgrade()
{
	if (this->_grade < 150)
		this->_grade++;
	else
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::upgrade(int i)
{
	if (this->_grade - i > 0)
		this->_grade -= i;
	else
		throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::downgrade(int i)
{
	if (this->_grade + i < 151)
		this->_grade += i;
	else
		throw Bureaucrat::GradeTooHighException();
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat &rhs)
{
	out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return out;
}

void Bureaucrat::signForm(AForm &form)
{
	if (form.getGradeToSign() < this->getGrade())
	{
		std::cout << this->getName() << " cannot sign " << form.getName() << " because his grade is too low" << std::endl;
	}
	else if (form.getSigned())
	{
		std::cout << this->getName() << " cannot sign " << form.getName() << " because it is already signed" << std::endl;
	}
	else
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signs " << form.getName() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executes " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}