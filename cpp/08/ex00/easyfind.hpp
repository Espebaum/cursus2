#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <string>
# include <vector>
# include <list>
# include <deque>
# include <algorithm>
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

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
    typename T::iterator it;
	
	it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::runtime_error("Cannot find value in Container");
	return it;
}

#endif

	// typename T::iterator it;

	// for (it = container.begin(); it != container.end(); it++)
	// 	if (*it == value)
	// 		return it;

	// if (it == container.end())
	// 	throw std::runtime_error("Cannot find value in Container");
	
	// return container.end();
