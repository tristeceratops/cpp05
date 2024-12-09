#pragma once

#include <iostream>

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
		
		static const char *GradeTooHighException;
		static const char *GradeTooLowException;
};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &rhs);