#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>

#define RESET		"\033[0m"
#define BOLDBLACK	"\033[1m\033[30m"
#define BOLDRED		"\033[1m\033[31m"
#define BOLDGREEN	"\033[1m\033[32m"
#define BOLDYELLOW	"\033[1m\033[33m"
#define BOLDBLUE	"\033[1m\033[34m"
#define BOLDMAGENTA	"\033[1m\033[35m"
#define BOLDCYAN	"\033[1m\033[36m"
#define BOLDWHITE	"\033[1m\033[37m"

class	Bureaucrat;

class Form
{
	private:
		const std::string	name;
		bool	indicator;
		const int	gradeSigned;
		const int	gradeExecute;
	public:
		Form();
		~Form();
		Form(std::string name, int grade);
		std::string	getName() const;
		bool	getIndicator() const;
		int		getGradeSigned() const;
		int		getGradeExecute() const;
		void	beSigned(const Bureaucrat &ref);
		class GradeTooHighException : public std::exception
		{
			public:
				const char	*what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char	*what() const throw();
		};
		Form(const Form& ref);
		Form& operator=(const Form& ref);
};

std::ostream& operator<<(std::ostream &os, const Form& ref);
void	printLine(int line);

#endif
