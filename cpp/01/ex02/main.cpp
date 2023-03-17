#include <iostream>

#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

int main(void)
{
	std::string		brain = "HI THIS IS BRAIN";
	std::string		*stringPTR = &brain;
	std::string&	stringREF = brain;

	std::cout << BOLDWHITE << "Brain     Address : " << BOLDBLUE << &brain << std::endl;
	std::cout << BOLDWHITE << "stringPTR Address : " << BOLDBLUE << stringPTR << std::endl;
	std::cout << BOLDWHITE<< "stringREF Address : " << BOLDBLUE << &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << BOLDWHITE << "The value of the string Brain     : " << BOLDBLUE << brain <<std::endl;
	std::cout << BOLDWHITE << "The value pointed to by stringPTR : " << BOLDBLUE << *stringPTR << std::endl;
	std::cout << BOLDWHITE << "The value pointed to by stringREF : " << BOLDBLUE << stringREF << std::endl;
	return (0);
}
