#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2) 
	{
		std::cout<<BOLDRED<<"Invalid input!"<<std::endl;
	}
	else
	{
		std::string	toStr(argv[1]);
		ScalarConverter::convert(toStr);
	}
	return 0;
}
