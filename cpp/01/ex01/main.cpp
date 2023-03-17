#include "Zombie.hpp"

// void	leakcheck()
// {
// 	std::cout << std::endl << BOLDWHITE << "----------------" << std::endl;
// 	std::cout << BOLDCYAN << "leak checking..." << std::endl;
// 	std::cout << BOLDWHITE << "----------------" << RESET << std::endl;
// 	system("leaks Horde");
// }

int main(void)
{
	// atexit(leakcheck);

	std::cout << BOLDWHITE << "----------------------------------------------------------" << std::endl;
	std::cout << BOLDYELLOW << "              Horde of Zombies has appeared!!" << std::endl;
	std::cout << BOLDWHITE << "----------------------------------------------------------" << std::endl;

	int N = 3;
	Zombie  *first = zombieHorde(N, "Zerg");
	
	std::cout << std::endl;
	std::cout << BOLDWHITE << "----------------------------------------------------------" << std::endl;
	std::cout << BOLDYELLOW << "    Someone has detroyed Zombies constructed in heap..." << std::endl;
	std::cout << BOLDWHITE << "----------------------------------------------------------" << std::endl;
	
	delete[] first;
	return (0);
}
