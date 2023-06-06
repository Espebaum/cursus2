#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try 
	{
		//  --- Try & Catch when Bureaucrat's grade is too high --- //
		// try
		// {
		// 	Bureaucrat	test("Queen Elizabeth", 0);
		// }
		// catch (std::exception &e)
		// {
		// 	std::cout<<BOLDRED<<e.what()<<RESET<<std::endl;
		// }

		Bureaucrat	approver1("Jane", 10);
		Bureaucrat	approver2("Wendy", 46);
		Bureaucrat	executor1("James", 2);
		Bureaucrat	executor2("Alex", 146);

		ShrubberyCreationForm	Shru("Gwan");	// target is "Gwan", sign 145 / exec 137
		RobotomyRequestForm		Robo("Ape");	// target is "Ape", sign 72 / exec 45
		PresidentialPardonForm	Pre("Winter Soldier");	// target is "Winter Soldier", sign 25 / exec 5

		Shru.beSigned(approver1);
		Robo.beSigned(approver1);	
		Pre.beSigned(approver1);

		Shru.execute(executor1);
		Robo.execute(executor1);	
		Pre.execute(executor1);
	}
	catch (std::exception &e)
	{
		std::cout<<BOLDRED<<e.what()<<RESET<<std::endl;
	}
	return (0);
}
