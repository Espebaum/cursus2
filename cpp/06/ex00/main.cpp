#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout<<BOLDRED<<"Invalid input!"<<std::endl;
		std::cout<<BOLDCYAN<< "Correct Input "<< \
		BOLDYELLOW<<" : ./Convert \"string\""<<std::endl; 
	} else {
		std::cout<<Convert(argv[1])<<std::endl;
	}
	return 0;
}
