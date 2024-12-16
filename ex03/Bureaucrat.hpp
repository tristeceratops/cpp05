#pragma once

#include <iostream>
#include "AForm.hpp"


class AForm;

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
		
		void signForm(AForm &form);
		void executeForm(AForm const &form);
		
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &rhs);