#include "Zombie.hpp"

// void	leakcheck()
// {
// 	system("leaks Zombie");
// }

int main(void)
{
	// atexit(leakcheck);
	std::cout << BOLDWHITE << "----------------------------------------------------------" << std::endl;
	std::cout << BOLDYELLOW << "Zombies which generated in " << BOLDBLUE << "STACK " \
	<< BOLDYELLOW << "die when function ends..." << std::endl;
	std::cout << BOLDWHITE << "----------------------------------------------------------" << std::endl;
	
	Zombie	default1;
	default1.announce();
	Zombie	stack("Stack Zombie");
	stack.announce();
	Zombie	stack2("Stack Zombie2");
	stack2.announce();
	std::cout << std::endl;

	std::cout << BOLDWHITE << "----------------------------------------------------------" << std::endl;
	std::cout << BOLDYELLOW << "Zombies which generated in " << BOLDBLUE << "HEAP " \
	<< BOLDYELLOW << "die when data freed..." << std::endl;
	std::cout << BOLDWHITE << "----------------------------------------------------------" << std::endl;
	
	Zombie	*heap = newZombie("Heap Zombie");
	heap->announce();
	std::cout << std::endl;

	std::cout << BOLDWHITE << "----------------------------------------------------------" << std::endl;
	std::cout << BOLDYELLOW << "            Random Zombie has been appeared!!!" << std::endl;
	std::cout << BOLDWHITE << "----------------------------------------------------------" << std::endl;
	randomChump("Random Zombie");
	std::cout << std::endl;
	
	std::cout << BOLDWHITE << "----------------------------------------------------------" << std::endl;
	std::cout << BOLDYELLOW << "     Someone has detroyed Zombie constructed in heap..." << std::endl;
	std::cout << BOLDWHITE << "----------------------------------------------------------" << std::endl;
	delete heap;
	std::cout << std::endl;

	std::cout << BOLDWHITE << "----------------------------------------------------------" << std::endl;
	std::cout << BOLDRED << "FUNCTION ENDED" << std::endl;
	std::cout << BOLDWHITE << "----------------------------------------------------------" << std::endl;
	return (0);
}
