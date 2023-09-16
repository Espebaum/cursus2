#include <iostream>
#include <cmath>
#include "color.hpp"

int main()
{
    double b;
	while (1)
	{
		std::cout<<BOLDYELLOW<<"Input any value that related with inf and nan : "<<RESET;
		std::cin>>b;
		if (std::isnan(b))
		{
			std::cout << BOLDRED << "NANI!!!\n";
		}
		else if (std::isinf(b))
		{
			std::cout<< BOLDMAGENTA << "INFINTIY!!!\n";
		}
		else if (static_cast<float>(b) && static_cast<double>(b))
		{
			std::cout << BOLDRED << static_cast<float>(b)<<std::endl;
			std::cout << BOLDRED << static_cast<double>(b)<<std::endl;
		}
		else
			break ;
	}
	return 0;
}
