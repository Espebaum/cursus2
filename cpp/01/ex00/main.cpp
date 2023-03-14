#include "Zombie.hpp"

int main(void)
{
	std::cout << BOLDWHITE << "---------------------------------------------------------" << std::endl;
	std::cout << BOLDYELLOW << "Zombies which generated in " << BOLDBLUE << "STACK " \
	<< BOLDYELLOW << "die when function end..." << std::endl;
	std::cout << BOLDWHITE << "---------------------------------------------------------" << std::endl;
	Zombie	stack("stack Zombie");
	stack.announce();
	Zombie	stack2("stack Zombie2");
	stack2.announce();
	std::cout << std::endl;

	std::cout << BOLDWHITE << "---------------------------------------------------------" << std::endl;
	std::cout << BOLDYELLOW << "Zombies which generated in " << BOLDBLUE << "HEAP " \
	<< BOLDYELLOW << "die when data freed..." << std::endl;
	std::cout << BOLDWHITE << "---------------------------------------------------------" << std::endl;
	Zombie	*heap = newZombie("heap Zombie");
	heap->announce();	
	std::cout << std::endl;

	randomChump("foo");
	std::cout << std::endl;
	
	delete heap;
	std::cout << std::endl << "FUNCTION ENDED" << std::endl << std::endl;
	
	return (0);
}
