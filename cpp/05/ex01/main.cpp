#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try 
	{
		Bureaucrat	bur("James", 2);
		// Bureaucrat	test("Queen Elizabeth", 0);
		Form		form1("Building City Hall", 1);
		form1.beSigned(bur);
		std::cout<<form1<<std::endl;
		bur.signForm(form1);
	}
	catch (std::exception &e)
	{
		std::cout<<BOLDRED<<e.what()<<RESET<<std::endl;
	}
	return (0);
}
