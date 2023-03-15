#include "Zombie.hpp"

// void	leakcheck()
// {
// 	system("leaks Horde");
// }

int main(void)
{
	// atexit(leakcheck);

	std::cout << BOLDWHITE << "----------------------------------------------------------" << std::endl;
	std::cout << BOLDYELLOW << "          Horde of Zombies has been appeared!!!" << std::endl;
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
