#include "AForm.hpp"

const char* AForm::GradeTooHighException = "AForm::GradeTooHighException";
const char* AForm::GradeTooLowException = "AForm::GradeTooLowException";

AForm::AForm() : _name("noname"), _signed(false), _gradeToSign(150), _gradeToExecute(150){}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooLowException;
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooHighException;
}

AForm::AForm(const AForm &copy) : _name(copy.getName()), _signed(copy.getSigned()), _gradeToSign(copy.getGradeToSign()), _gradeToExecute(copy.getGradeToExecute()){}

AForm::~AForm() {}

AForm& AForm::operator=(const AForm &rhs)
{
	if (this != &rhs)
	{
		this->_signed = rhs.getSigned();
	}
	return *this;
}

std::string AForm::getName() const
{
	return this->_name;
}

bool AForm::getSigned() const
{
	return this->_signed;
}

int AForm::getGradeToSign() const
{
	return this->_gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return this->_gradeToExecute;
}

// void AForm::beSigned(Bureaucrat &bureaucrat)
// {
// 	if (bureaucrat.getGrade() <= this->_gradeToSign)
// 		this->_signed = true;
// 	else
// 		throw AForm::GradeTooLowException;
// }

std::ostream& operator<<(std::ostream &out, const AForm &rhs)
{
	out << rhs.getName() << ", Aform grade to sign " << rhs.getGradeToSign() << ", grade to execute " << rhs.getGradeToExecute() << " " << (rhs.getSigned() ? "is signed":"is not signed") << ".";
	return out;
}