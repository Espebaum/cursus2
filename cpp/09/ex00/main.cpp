#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << BOLDRED << "Invalid Argument!" << std::endl;
		return 0;
	}
	else
	{
		BitcoinExchange		Ex;
		Ex.show(argv[1]);
	}

	return 0;
}
