#ifndef ITER_HPP
# define ITER_HPP

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
void    iter(T* array, size_t length, void (*func)(T&)) //const인거 하나 추가
{
	for (size_t i = 0; i < length; i++)
	{
		func(array[i]);
	}
}

template<typename T>
void	next(T &str)
{
	str++;
}

template<> // template specialization
void	next(std::string& str) 
{
    for (size_t i = 0; i < str.length(); i++) {
        str[i]++;
    }
}

template<typename T>
void	print(T &str)
{
	std::cout<<str<<' ';
}

#endif
