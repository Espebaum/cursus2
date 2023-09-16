#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>
# include <string>

#define RESET		"\033[0m"
#define BOLDBLACK	"\033[1m\033[30m"
#define BOLDRED		"\033[1m\033[31m"
#define BOLDGREEN	"\033[1m\033[32m"
#define BOLDYELLOW	"\033[1m\033[33m"
#define BOLDBLUE	"\033[1m\033[34m"
#define BOLDMAGENTA	"\033[1m\033[35m"
#define BOLDCYAN	"\033[1m\033[36m"
#define BOLDWHITE	"\033[1m\033[37m"

template<typename T>
void	swap(T &a, T &b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template<typename T>
T	min(T &a, T &b)
{
	if (a < b)
		return a;
	else
		return b;
}

template<typename T>
const T	min(const T &a, const T &b)
{
	if (a < b)
		return a;
	else
		return b;
}

template<typename T>
T	max(T &a, T &b)
{
	if (a > b)
		return a;
	else
		return b; 
}

template<typename T>
const T	max(const T &a, const T &b)
{
	if (a > b)
		return a;
	else
		return b; 
}

#endif
