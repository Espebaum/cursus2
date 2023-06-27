#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

#define RESET		"\033[0m"
#define BOLDBLACK   "\033[1m\033[30m"
#define BOLDRED     "\033[1m\033[31m"
#define BOLDGREEN   "\033[1m\033[32m"
#define BOLDYELLOW  "\033[1m\033[33m"
#define BOLDBLUE    "\033[1m\033[34m"
#define BOLDMAGENTA "\033[1m\033[35m"
#define BOLDCYAN    "\033[1m\033[36m"
#define BOLDWHITE   "\033[1m\033[37m"

class Bureaucrat
{
	private:
		const std::string	name;
		int	grade;	
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		~Bureaucrat();
		std::string	getName() const;
		int	getGrade() const;
		void incrementGrade();
		void decrementGrade();
		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw(); 
				//throw() is Dynamic Exception Specification, we can expect that
				//this function will not occur any type of exception explicitly.
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw(); //Also here
		};
		Bureaucrat(const Bureaucrat& ref);
		Bureaucrat& operator=(const Bureaucrat& ref);
	};

std::ostream& operator<<(std::ostream &os, const Bureaucrat& ref);

#endif
