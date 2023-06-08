#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try 
	{
		try
		{
			Bureaucrat	test("Queen Elizabeth", 0);
			Bureaucrat	none("None", 155);
		}
		catch (std::exception &e)
		{
			std::cout<<BOLDRED<<e.what()<<RESET<<std::endl;
		}

		Bureaucrat	James("James", 2);
		
		try
		{
			Form	testForm("Building the Pentagon", 0);
			Form	none("NonExist", 155);
		}
		catch(const std::exception& e)
		{
			std::cout<<BOLDRED<<e.what()<<RESET<<std::endl;
		}
		
		Form	form1("Hiring principle", 1);
		Form	form2("Building School", 10);
		
		form1.beSigned(James);
		form2.beSigned(James);

		std::cout<<form1<<std::endl;
		std::cout<<form2<<std::endl;

		James.signForm(form1);
		James.signForm(form2);
	}
	catch (std::exception &e)
	{
		std::cout<<BOLDRED<<e.what()<<RESET<<std::endl;
	}
	return (0);
}
