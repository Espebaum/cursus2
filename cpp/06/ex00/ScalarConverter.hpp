#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cmath>
# include <cstdlib>
# include <stdexcept>

#define RESET		"\033[0m"
#define BOLDBLACK	"\033[1m\033[30m"
#define BOLDRED		"\033[1m\033[31m"
#define BOLDGREEN	"\033[1m\033[32m"
#define BOLDYELLOW	"\033[1m\033[33m"
#define BOLDBLUE	"\033[1m\033[34m"
#define BOLDMAGENTA	"\033[1m\033[35m"
#define BOLDCYAN	"\033[1m\033[36m"
#define BOLDWHITE	"\033[1m\033[37m"

#define ND "Non displayable"
#define NP "impossible"

class ScalarConverter
{
	private:
		static bool			err;
		const std::string	input;
		const double		value;
		ScalarConverter();

	public:
		//OCCF
  		explicit ScalarConverter(const std::string& input);
		ScalarConverter(const ScalarConverter& ref);
		~ScalarConverter();
		ScalarConverter& operator=(const ScalarConverter& ref);

		// Converting Functions
		char	toChar() const;
		int		toInt() const;
		float	toFloat() const;
		double	toDouble() const;

		// getter Functions
		bool	getErr() const;
		double	getValue() const;
		std::string	getInput() const;
};

std::ostream&	operator<<(std::ostream& os, const ScalarConverter &c);

#endif
