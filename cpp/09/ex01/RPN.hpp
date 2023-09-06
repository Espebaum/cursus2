#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>

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
        std::string input;
    public:
        RPN();
        RPN(const RPN& ref);
        ~RPN();
        RPN& operator=(const RPN& ref);
};

#endif
