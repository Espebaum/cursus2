#pragma once

# include <iostream>
# include <string>
# include <stack>
# include <sstream>

#define RESET		"\033[0m"
#define BOLDBLACK	"\033[1m\033[30m"
#define BOLDRED		"\033[1m\033[31m"
#define BOLDGREEN	"\033[1m\033[32m"
#define BOLDYELLOW	"\033[1m\033[33m"
#define BOLDPURPLE	"\033[1m\033[34m"
#define BOLDMAGENTA	"\033[1m\033[35m"
#define BOLDBLUE	"\033[1m\033[36m"
#define BOLDWHITE	"\033[1m\033[37m"

class RPN
{
	private:
		std::string         input;
		std::stack<double>  value;

	public:
		RPN();
		RPN(const RPN& ref);
		~RPN();
		RPN& operator=(const RPN& ref);

		// functions
		void    split(std::string formula);
		void	readValue(std::string token);
		void	operate(std::string op);

		// trigger
		void    calculate(std::string argv);

		// exception
		class ValueError : public std::exception
		{
			public:
				const char* what() const throw();
		};

};
