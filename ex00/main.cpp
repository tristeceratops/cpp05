#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat* Albert = NULL;
    Bureaucrat* Robert = NULL;
    try
    {
        Albert = new Bureaucrat("Albert", 155);
        Robert = new Bureaucrat("Robert", -4);
    }
    catch(const char * error)
    {
        std::cerr << error << '\n';
    }
    try
    {
        Robert = new Bureaucrat("Robert", -4);
        Albert = new Bureaucrat("Albert", 155);
    }
    catch(const char * error)
    {
        std::cerr << error << '\n';
    }
    try
    {
        Robert = new Bureaucrat("Robert", 4);
        Albert = new Bureaucrat("Albert", 85);
    }
    catch(const char * error)
    {
        std::cerr << error << '\n';
    }
    Bureaucrat Roger = Bureaucrat("Roger", 47);
    std::cout << *Robert << std::endl;
    std::cout << *Albert << std::endl;
    std::cout << Roger << std::endl;

    delete Albert;
    delete Robert;
}