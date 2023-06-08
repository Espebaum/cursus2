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
		// 	Bureaucrat	none("None", 156);
		// }
		// catch (std::exception &e)
		// {
		// 	std::cout<<BOLDRED<<e.what()<<RESET<<std::endl;
		// }

		Bureaucrat	approver1("Jane", 10);
		Bureaucrat	approver2("Wendy", 18);
		
		Bureaucrat	executor1("James", 140);
		Bureaucrat	executor2("Alex", 1);

		ShrubberyCreationForm	Shru("Gwan");	// target is "Gwan", sign 145 / exec 137
		RobotomyRequestForm		Robo("Ape");	// target is "Ape", sign 72 / exec 45
		PresidentialPardonForm	Pre("Winter Soldier");	// target is "Winter Soldier", sign 25 / exec 5

		// ---- Group 1 ---- //

		// Shru.beSigned(approver1);
		// Robo.beSigned(approver1);	
		// Pre.beSigned(approver1);

		// approver1.signForm(Shru);
		// approver1.signForm(Robo);
		// approver1.signForm(Pre);
		// std::cout<<std::endl;

		// executor1.executeForm(Shru);
		// executor1.executeForm(Robo);
		// executor1.executeForm(Pre);

		// ---- Group 2 ---- //

		Shru.beSigned(approver2);
		Robo.beSigned(approver2);	
		Pre.beSigned(approver2);

		approver2.signForm(Shru);
		approver2.signForm(Robo);
		approver2.signForm(Pre);
		std::cout<<std::endl;

		executor2.executeForm(Shru);
		executor2.executeForm(Robo);
		executor2.executeForm(Pre);

	}
	catch (std::exception &e)
	{
		std::cout<<BOLDRED<<e.what()<<RESET<<std::endl;
	}
	return (0);
}
