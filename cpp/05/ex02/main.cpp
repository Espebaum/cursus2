#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	try 
	{
		// try
		// {
		// 	Bureaucrat	test("Queen Elizabeth", 0);
		// }
		// catch (std::exception &e)
		// {
		// 	std::cout<<BOLDRED<<e.what()<<RESET<<std::endl;
		// }

		Bureaucrat	bur("James", 2);
		
		// try
		// {
		// 	Form	testForm("Building the Pentagon", 0);
		// }
		// catch(const std::exception& e)
		// {
		// 	std::cout<<BOLDRED<<e.what()<<RESET<<std::endl;
		// }
		
		ShrubberyCreationForm	form("Test");
		form.beSigned(bur);

		form.execute(bur);
	}
	catch (std::exception &e)
	{
		std::cout<<BOLDRED<<e.what()<<RESET<<std::endl;
	}
	return (0);
}
