#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

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
		Bureaucrat(const Bureaucrat& ref);
		Bureaucrat& operator=(const Bureaucrat& ref);
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		std::string	getName() const;
		int	getGrade() const;
		void incrementGrade();
		void decrementGrade();
		Bureaucrat& operator<<(const Bureaucrat &ref);
		class GradeTooHighException : public std::exception
		{
			public:
				const char *what(void) const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what(void) const throw();
		};
};

#endif
