#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("noname"){}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy.getName(), copy.getGradeToSign(), copy.getGradeToExecute()), _target(copy.getTarget()){}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	if (this != &rhs)
	{
		this->_target = rhs.getTarget();
	}
	return *this;
}

std::string RobotomyRequestForm::getTarget() const
{
	return this->_target;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSigned())
		throw AForm::FormNotSigned();
	else if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	else
	{
		std::cout << "Drilling noises..." << std::endl;
		if (rand() % 2)
			std::cout << this->getTarget() << " has been robotomized successfully." << std::endl;
		else
			std::cout << this->getTarget() << " robotomization failed." << std::endl;
	}
}

std::ostream& operator<<(std::ostream &out, const RobotomyRequestForm &rhs)
{
	out << rhs.getName() << ", RobotomyRequestForm grade to sign " << rhs.getGradeToSign() << ", grade to execute " << rhs.getGradeToExecute() << " " << (rhs.getSigned() ? "is signed":"is not signed") << ".";
	return out;
}