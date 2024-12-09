#include "Bureaucrat.hpp"
#include "Form.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"


int main()
{
    Bureaucrat* Albert = NULL;
    Bureaucrat* Robert = NULL;
    try
    {
        Albert = new Bureaucrat("Albert", 151);
        Robert = new Bureaucrat("Robert", -4);
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "constructor Bureaucrat 1 catch error : " << e.what() << '\n' << RESET;
    }
    try
    {
        Robert = new Bureaucrat("Robert", 0);
        Albert = new Bureaucrat("Albert", 155);
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "constructor Bureaucrat 2 catch error : " << e.what() << '\n' << RESET;
    }
    try
    {
        Robert = new Bureaucrat("Robert", 1);
        Albert = new Bureaucrat("Albert", 150);
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "constructor Bureaucrat 3 catch error : " << e.what() << '\n' << RESET;
    }
    Bureaucrat Roger = Bureaucrat("Roger", 47);
    std::cout << *Robert << std::endl;
    std::cout << *Albert << std::endl;
    std::cout << Roger << std::endl;
	try
	{
		Roger.downgrade(150);
	}
	catch(const std::exception& e)
	{
        std::cerr << RED << "Downgrade catch error : " << e.what() << '\n' << RESET;
	}	
	std::cout << Roger << std::endl;
	try
	{
		Roger.upgrade(150);
	}
	catch(const std::exception& e)
	{
        std::cerr << RED << "upgrade catch error : " << e.what() << '\n' << RESET;
	}
	std::cout << Roger << std::endl;
	
	Form *f1 = NULL;
	Form *f2 = NULL;

	try
	{
		f1 = new Form("f1", 155, 151);
	}
	catch(const std::exception& e)
	{
        std::cerr << RED << "constructor Form 1 catch error : " << e.what() << '\n' << RESET;
	}

	try
	{
		f2 = new Form("f2", 4, 0);
	}
	catch(const std::exception& e)
	{
        std::cerr << RED << "constructor Form 2 catch error : " << e.what() << '\n' << RESET;
	}

	try
	{
		f2 = new Form("f2", 4, 4);
		f1 = new Form("f1", 80, 80);
	}
	catch(const std::exception& e)
	{
        std::cerr << RED << "constructor Form 3 catch error : " << e.what() << '\n' << RESET;
	}

	try
	{
		f1->beSigned(Roger);
	}
	catch(const std::exception& e)
	{
        std::cerr << RED << "beSigned 1 catch error : " << e.what() << '\n' << RESET;
	}

	try
	{
		f2->beSigned(Roger);
	}
	catch(const std::exception& e)
	{
        std::cerr << RED << "beSigned 2 catch error : " << e.what() << '\n' << RESET;
	}
	std::cout << *f1 << std::endl;
	std::cout << *f2 << std::endl;

	Roger.signForm(*f1);
	Roger.signForm(*f2);
	Robert->signForm(*f1);
	Robert->signForm(*f2);



    delete Albert;
    delete Robert;

	delete f1;
	delete f2;
}