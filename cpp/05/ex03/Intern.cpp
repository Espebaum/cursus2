#include "Intern.hpp"

const char	*Intern::NoTypeExistException::what(void) const throw()
{
	return ("There is no Type matching!");
}

AForm*	Intern::makeForm(std::string formName, std::string formTarget)
{
	int	type = 3;
	std::string forms[3] = {"Shrubbery Creation", "Robotomy Request", "Presidential Pardon"};

	for (int i = 0; i < 3; i++)
	{
		if (formName == forms[i])
		{
			type = i;
			std::cout << BOLDCYAN << "Intern" << RESET << " creates Form, the type is " \
			<< BOLDBLUE << "<" << forms[i] << ">" << std::endl; 
		}
	}

	try
	{
		switch (type)
		{
			case 0:
				return new ShrubberyCreationForm(formTarget);
				break ;
			case 1:
				return new RobotomyRequestForm(formTarget);
				break ;
			case 2:
				return new PresidentialPardonForm(formTarget);
				break ;
			case 3:
				throw Intern::NoTypeExistException();
		}
	}
	catch (std::exception &e)
	{
		std::cout << BOLDRED << e.what() << RESET << std::endl;
	}
	
	return NULL;
}

Intern::Intern(const Intern &ref) 
{
	static_cast<void> (ref);
}

Intern& Intern::operator=(const Intern &ref) 
{
	static_cast<void> (ref);
	return (*this);
}
