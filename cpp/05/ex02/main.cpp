#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try 
	{
		try
		{
			Bureaucrat	test("Queen Elizabeth", 0);
		}
		catch (std::exception &e)
		{
			std::cout<<BOLDRED<<e.what()<<RESET<<std::endl;
		}

		Bureaucrat	bur("James", 2);
		
		try
		{
			Form	testForm("Building the Pentagon", 0);
		}
		catch(const std::exception& e)
		{
			std::cout<<BOLDRED<<e.what()<<RESET<<std::endl;
		}
		
		Form		form("Building School", 10);

		form1.beSigned(bur);
		std::cout<<form<<std::endl;
		bur.signForm(form);
	}
	catch (std::exception &e)
	{
		std::cout<<BOLDRED<<e.what()<<RESET<<std::endl;
	}
	return (0);
}
