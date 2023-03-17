#include "Harl.hpp"

// void	leakcheck()
// {
// 	std::cout << std::endl << BOLDWHITE << "----------------" << std::endl;
// 	std::cout << BOLDGREEN << "leak checking..." << std::endl;
// 	std::cout << BOLDWHITE << "----------------" << RESET << std::endl;
// 	system("leaks harlFilter");
// }

int	main(int argc, char **argv)
{
	// atexit(leakcheck);
	if (argc == 1)
	{
		std::cerr << BOLDRED << "Error! Harl must do something!" << std::endl;
		return (1);
	}
	else if (argc != 2)
	{
		std::cerr << BOLDRED << "Error! Harl cannot do several things at the same time!" << std::endl;
		return (1);
	}

	std::cout << BOLDWHITE << "------------------------------------------------------" << std::endl;
	std::cout << BOLDWHITE << "It seems like Harl wants to" << BOLDRED << " complain " << BOLDWHITE << \
	"about somthing..." << std::endl;
	std::cout << BOLDWHITE << "------------------------------------------------------" << std::endl;

	Harl	harl;
	std::string	levels[5] = {"", "DEBUG", "INFO", "WARNING", "ERROR"};
	
	int	com[5] = {0, };
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		if (levels[i] == argv[1])
			com[i] = i;
		sum += com[i];
	}

	switch (sum)
	{
		case 1:
			harl.complain("DEBUG");
		case 2:
			harl.complain("INFO");
		case 3:
			harl.complain("WARNING");
		case 4:
			harl.complain("ERROR");
			break;
		default:
			std::cout << BOLDBLUE << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
	return (0);
}
