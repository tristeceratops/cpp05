#include "Bureaucrat.hpp"

#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

int main()
{

    Bureaucrat* Albert = NULL;
    Bureaucrat* Robert = NULL;
    try
    {
        Albert = new Bureaucrat("Albert", 155); //too high
        Robert = new Bureaucrat("Robert", -4); //too low
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "constructor 1 catch error : " << e.what() << '\n' << RESET;
    }
    try
    {
        Robert = new Bureaucrat("Robert", -4); //too low
        Albert = new Bureaucrat("Albert", 155); //too high
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "constructor 2 catch error : " << e.what() << '\n' << RESET;
    }
    try
    {
        Robert = new Bureaucrat("Robert", 4);
        Albert = new Bureaucrat("Albert", 85);
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "constructor 3 catch error : " << e.what() << '\n' << RESET;
    }
    Bureaucrat Roger = Bureaucrat("Roger", 47);
    std::cout << *Robert << std::endl;
    std::cout << *Albert << std::endl;
    std::cout << Roger << std::endl;
	try
	{
		Roger.downgrade(150); //too low after downgrade
	}
	catch(const std::exception& e)
	{
        std::cerr << RED << "Downgrade catch error : " << e.what() << '\n' << RESET;
	}	
	std::cout << Roger << std::endl;
	try
	{
		Roger.upgrade(300); //too high after upgrade
	}
	catch(const std::exception& e)
	{
        std::cerr << RED << "upgrade catch error : " << e.what() << '\n' << RESET;
	}
	std::cout << Roger << std::endl;
	try
	{
		Roger.upgrade(4);
		Roger.upgrade();
	}
	catch(const std::exception& e)
	{
        std::cerr << RED << "upgrade catch error : " << e.what() << '\n' << RESET;
	}
	std::cout << Roger << std::endl;
	try
	{
		Roger.downgrade(15);
		Roger.downgrade();
	}
	catch(const std::exception& e)
	{
        std::cerr << RED << "upgrade catch error : " << e.what() << '\n' << RESET;
	}
	std::cout << Roger << std::endl;

    delete Albert;
    delete Robert;
}