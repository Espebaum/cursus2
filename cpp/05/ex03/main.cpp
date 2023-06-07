#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

// void	leakcheck()
// {
// 	std::cout<<RESET<<std::endl;
// 	system("leaks Intern");
// }

int main()
{
	// atexit(leakcheck);

	std::cout<<BOLDYELLOW<<"-----------------------------------"<<std::endl;
	std::cout<<"        The Approvers enter"<<std::endl;
	std::cout<<"-----------------------------------"<<RESET<<std::endl;
	
	Bureaucrat	approver1("Alex", 146);
	Bureaucrat	approver2("Bendy", 17);
	Bureaucrat	approver3("James", 120);

	std::cout<<approver1<<std::endl<<approver2<<std::endl<<approver3<<std::endl;

	std::cout<<BOLDGREEN<<"-----------------------------------"<<std::endl;
	std::cout<<"        The Executors enter"<<std::endl;
	std::cout<<"-----------------------------------"<<RESET<<std::endl;

	Bureaucrat	executor1("Anne", 1000);
	Bureaucrat	executor2("Brigit", 150);
	Bureaucrat	executor3("Jane", 2);

	std::cout<<executor1<<std::endl<<executor2<<std::endl<<executor3<<std::endl<<std::endl;

	std::cout<<BOLDCYAN<<"-----------------------------------"<<RESET<<std::endl;
	std::cout<< " The bureaucrats summon the "<<BOLDCYAN<< "Intern" <<RESET<<std::endl;
	std::cout<<BOLDCYAN<<"-----------------------------------"<<RESET<<std::endl;
	Intern	someRandomIntern;

	AForm*	rrf1;
	AForm*	rrf2;
	AForm*	rrf3;

	rrf1	= someRandomIntern.makeForm("Shrubbery Creation", "Gwan");
	rrf2	= someRandomIntern.makeForm("Robotomy Request", "Bender");
	rrf3	= someRandomIntern.makeForm("Presidential Pardon", "Winter Soldier");
	
	someRandomIntern.makeForm("FormDoNotExist", "NoTarget");

	std::cout<<std::endl;
	std::cout<<BOLDGREEN<<"-----------------------------------"<<std::endl;
	std::cout<<RESET<<"    Approvers are signing forms"<<std::endl;
	std::cout<<BOLDGREEN<<"-----------------------------------"<<RESET<<std::endl;

	rrf1->beSigned(approver1);
	rrf2->beSigned(approver2);
	rrf3->beSigned(approver3);

	approver1.signForm(*rrf1);
	approver2.signForm(*rrf2);
	approver3.signForm(*rrf3);

	std::cout<<std::endl;
	std::cout<<*rrf1<<std::endl<<std::endl<<*rrf2<<std::endl<<std::endl<<*rrf3<<std::endl<<std::endl;
	
	std::cout<<BOLDRED<<"-----------------------------------"<<std::endl;
	std::cout<<RESET<<"   Executors are executing forms"<<std::endl;
	std::cout<<BOLDRED<<"-----------------------------------"<<RESET<<std::endl;

	rrf1->execute(executor1);
	rrf2->execute(executor2);
	rrf3->execute(executor3);

	delete	rrf1;
	delete	rrf2;
	delete	rrf3;

	return (0);
}
