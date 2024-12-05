#pragma once

#include <iostream>

class Bureaucrat
{
	private:
		const std::string	name;
		unsigned int		grade;
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
		
		static const char *GradeTooHighException;
		static const char *GradeTooLowException;
};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &rhs);