#include <iostream>
#include <string>
#include <sstream>

int main(void)
{
	std::stringstream	tmp;
	int	i = 0;
	std::string	a = "Hi";
	tmp << i << a;
	std::cout << tmp.str() << std::endl;
}
