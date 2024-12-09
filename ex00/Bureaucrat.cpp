#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("noname"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy.getName()), _grade(copy.getGrade()) {}

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
        throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::downgrade()
{
    if (this->_grade < 150)
        this->_grade++;
    else
        throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::upgrade(int i)
{
    if (this->_grade - i > 0)
        this->_grade -= i;
    else
        throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::downgrade(int i)
{
    if (this->_grade + i < 151)
        this->_grade += i;
    else
        throw Bureaucrat::GradeTooLowException();
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat &rhs)
{
    out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
    return out;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}