#include "Form.hpp"

const char* Form::GradeTooHighException = "Form::GradeTooHighException";
const char* Form::GradeTooLowException = "Form::GradeTooLowException";

Form::Form() : _name("noname"), _signed(false), _gradeToSign(150), _gradeToExecute(150){}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooLowException;
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooHighException;
}

Form::Form(const Form &copy) : _name(copy.getName()), _signed(copy.getSigned()), _gradeToSign(copy.getGradeToSign()), _gradeToExecute(copy.getGradeToExecute()){}

Form::~Form() {}

Form& Form::operator=(const Form &rhs)
{
	if (this != &rhs)
	{
		this->_signed = rhs.getSigned();
	}
	return *this;
}

std::string Form::getName() const
{
	return this->_name;
}

bool Form::getSigned() const
{
	return this->_signed;
}

int Form::getGradeToSign() const
{
	return this->_gradeToSign;
}

int Form::getGradeToExecute() const
{
	return this->_gradeToExecute;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_gradeToSign)
		this->_signed = true;
	else
		throw Form::GradeTooLowException;
}

std::ostream& operator<<(std::ostream &out, const Form &rhs)
{
	out << rhs.getName() << ", form grade to sign " << rhs.getGradeToSign() << ", grade to execute " << rhs.getGradeToExecute() << " " << (rhs.getSigned() ? "is signed":"is not signed") << ".";
	return out;
}