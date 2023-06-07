#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	private:
	public:
		// OCCF
		Intern() {};
		~Intern() {};
		Intern(const Intern& ref);
		Intern& operator=(const Intern& ref);

		// makeForm
		AForm	*makeForm(std::string formName, std::string formTarget);

		// Exception
		class NoTypeExistException : public std::exception
		{
			public:
				const char	*what() const throw();
		};
};

#endif
