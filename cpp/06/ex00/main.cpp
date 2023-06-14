#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout<<BOLDRED<<"Invalid input!"<<std::endl;
		std::cout<<BOLDCYAN<< "Correct Input "<< \
		BOLDYELLOW<<" : ./Convert \"string\""<<std::endl;
	} else {
		ScalarConverter		s(argv[1]);
		s.convert();
	}
	return 0;
}
