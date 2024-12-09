#pragma once

#include <iostream>
#include "Form.hpp"


class Form;

class Bureaucrat
{
	private:
		const std::string	_name;
		int		_grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &copy);

		~Bureaucrat();

		Bureaucrat &operator=(const Bureaucrat &rhs);
		
		std::string getName() const;
		int getGrade() const;
		void upgrade();
		void downgrade();
		void upgrade(int i);
		void downgrade(int i);
		
		void signForm(Form &form);
		
		static const char *GradeTooHighException;
		static const char *GradeTooLowException;
};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &rhs);