#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error" << std::endl;
		return 0;
	}
	else
	{
		RPN r;
		r.calculate(argv[1]);
	}

	return 0;   
}
