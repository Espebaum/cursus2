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

class whatever
{
	private:
		/* data */
	public:
		whatever(/* args */);
		whatever(const whatever& ref);
		~whatever();
		whatever& operator=(const whatever& ref);

		void	swap(int a, int b);
		int		min();
};

#endif
