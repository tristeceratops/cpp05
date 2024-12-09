#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;
	public:
		AForm();
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		AForm(const AForm &copy);

		virtual ~AForm();

		AForm &operator=(const AForm &rhs);

		std::string getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		virtual void beSigned(Bureaucrat &bureaucrat) = 0;

		static const char *GradeTooHighException;
		static const char *GradeTooLowException;

};

std::ostream	&operator<<(std::ostream &out, const AForm &rhs);
