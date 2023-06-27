#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout<<BOLDRED<<"Invalid input!"<<std::endl;
	} else {
		ScalarConverter		s(argv[1]);
		// ScalarConverter::convert(argv[1]);
	}
	return 0;
}
