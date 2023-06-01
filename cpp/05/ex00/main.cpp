#include "Bureaucrat.hpp"

int main()
{
	try
	{
		try
		{
			Bureaucrat	bur1("John", 0);
		}
		catch(const std::exception& e)
		{
			std::cerr<<BOLDRED<<e.what()<<std::endl;
		}
		Bureaucrat	freshman("Fred", 149);
		Bureaucrat	principle("Edward", 2);
		freshman.decrementGrade();
		principle.incrementGrade();
		std::cout<<freshman<<std::endl<<principle<<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr<<BOLDRED<<e.what()<<std::endl;
	}
	return (0);
}
