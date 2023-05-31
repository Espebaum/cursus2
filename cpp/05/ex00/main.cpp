#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat  bur1("James", 200);
        Bureaucrat  bur2("Jane", 150);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}
