#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat Albert = Bureaucrat("Albert", 155);
		Bureaucrat Robert = Bureaucrat("Robert", -4);
	}
	catch(const char * error)
	{
		std::cerr << error << '\n';
	}
	try
	{
		Bureaucrat Robert = Bureaucrat("Robert", -4);
		Bureaucrat Albert = Bureaucrat("Albert", 155);
	}
	catch(const char * error)
	{
		std::cerr << error << '\n';
	}
	
}