#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

void	leakcheck()
{
	std::cout << std::endl << BOLDWHITE << "----------------" << std::endl;
	std::cout << BOLDGREEN << "leak checking..." << std::endl;
	std::cout << BOLDWHITE << "----------------" << RESET << std::endl;
	system("leaks Weapon");
}

int main()
{
	// atexit(leakcheck);
	// std::cout << BOLDWHITE << "-----------------------------------------------" << std::endl;
	// std::cout << BOLDWHITE << "          New Hero" << BOLDBLUE << " Bob " << BOLDWHITE << "has appeared!!" << std::endl;
	// std::cout << BOLDWHITE << "-----------------------------------------------" << std::endl;
	
	//Code for HumanA
	{
		Weapon club = Weapon("crude spiked club");
		// std::cout << &club << '\n';

		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}

	// std::cout << std::endl << BOLDWHITE << "-----------------------------------------------" << std::endl;
	// std::cout << BOLDWHITE << "          New Hero" << BOLDBLUE << " Jim " << BOLDWHITE << "has appeared!!" << std::endl;
	// std::cout << BOLDWHITE << "-----------------------------------------------" << std::endl;
	
	//Code for HumanB
	{
		Weapon club = Weapon("crude spiked club");
		// std::cout << &club << '\n';

		HumanB jim("Jim");

		// jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}
