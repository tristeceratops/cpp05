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