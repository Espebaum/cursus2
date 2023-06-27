#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <string>
# include <cstdint>

#define RESET		"\033[0m"
#define BOLDBLACK	"\033[1m\033[30m"
#define BOLDRED		"\033[1m\033[31m"
#define BOLDGREEN	"\033[1m\033[32m"
#define BOLDYELLOW	"\033[1m\033[33m"
#define BOLDBLUE	"\033[1m\033[34m"
#define BOLDMAGENTA	"\033[1m\033[35m"
#define BOLDCYAN	"\033[1m\033[36m"
#define BOLDWHITE	"\033[1m\033[37m"
struct Data
{
	std::string	password;
	int			key;
	float		frac;
	double		dot;
};

void			initData(Data &d);
std::ostream&	operator<<(std::ostream &os, const Data &d);

#endif
