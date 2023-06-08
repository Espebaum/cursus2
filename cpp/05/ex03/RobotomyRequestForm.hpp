#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib> // add <stdlib.h> in c++ file, to use rand() function
#include <ctime> // to use time function, include ctime in function

#define ROBO 		"RobotomyRequestForm"
#define ROBO_SIGN	72
#define ROBO_EXEC	45
class RobotomyRequestForm : public AForm
{
	private:
		RobotomyRequestForm(); //Function that only works IN member function
	public:
		//Functions in OCCF		
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& ref);
		~RobotomyRequestForm();
		RobotomyRequestForm& operator=(const RobotomyRequestForm& ref);

		//Other Function
		void	execute(Bureaucrat const &executor) const;
};

#endif
