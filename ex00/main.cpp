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
        Albert = new Bureaucrat("Albert", 155);
        Robert = new Bureaucrat("Robert", -4);
    }
    catch(const char *error)
    {
        std::cerr << RED << "constructor 1 catch error : " << error << '\n' << RESET;
    }
    try
    {
        Robert = new Bureaucrat("Robert", -4);
        Albert = new Bureaucrat("Albert", 155);
    }
    catch(const char *error)
    {
        std::cerr << RED << "constructor 2 catch error : " << error << '\n' << RESET;
    }
    try
    {
        Robert = new Bureaucrat("Robert", 4);
        Albert = new Bureaucrat("Albert", 85);
    }
    catch(const char *error)
    {
        std::cerr << RED << "constructor 3 catch error : " << error << '\n' << RESET;
    }
    Bureaucrat Roger = Bureaucrat("Roger", 47);
    std::cout << *Robert << std::endl;
    std::cout << *Albert << std::endl;
    std::cout << Roger << std::endl;
	try
	{
		Roger.downgrade(150);
	}
	catch(const char *error)
	{
        std::cerr << RED << "Downgrade catch error : " << error << '\n' << RESET;
	}	
	std::cout << Roger << std::endl;
	try
	{
		Roger.upgrade(300);
	}
	catch(const char *error)
	{
        std::cerr << RED << "upgrade catch error : " << error << '\n' << RESET;
	}
	std::cout << Roger << std::endl;
	

    delete Albert;
    delete Robert;
}