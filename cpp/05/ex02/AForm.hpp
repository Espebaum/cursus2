#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <fstream>
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

class AForm
{
	private:
		const std::string	type;
		const std::string	name;
		bool	indicator;
		const int	gradeSigned;
		const int	gradeExecute;
	
	public:
		// Functions in OCCF
		AForm();
		AForm(std::string name, int signGrade, int executeGrade);
		AForm& operator=(const AForm& ref);
		AForm(const AForm& ref);
		virtual ~AForm() {};

		// Other Functions
		void			setType(const std::string type);
		std::string		getName() const;
		bool			getIndicator() const;
		int				getGradeSigned() const;
		int				getGradeExecute() const;
		void			beSigned(const Bureaucrat &ref);
		virtual void	execute(Bureaucrat const &executor) const = 0;
		void			executable(Bureaucrat const &executor) const;
		
		// Inner Classes define Exception 
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
		class DoesNotSignedException : public std::exception
		{
			public:
				const char	*what() const throw();
		};
		class FileOpenErrorException : public std::exception
		{
			public:
				const char	*what() const throw();
		};
};

std::ostream& operator<<(std::ostream &os, const AForm& ref);
void	printLine(int line);

#endif
