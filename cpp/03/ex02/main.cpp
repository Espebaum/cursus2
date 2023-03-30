#include "ClapTrap.hpp"

int	main()
{
	const std::string	target = "DUMMY";
	// fragTrap	frag1;
	ClapTrap*	clap;
	FragTrap	frag2("FRAG-TRAP");
	clap = &frag2;

	frag2.attack(target);
	frag2.takeDamage(rand() % 10);
	frag2.showAllStatus();
	frag2.highFivesGuy();

	std::cout << BOLDWHITE << "===================" << std::endl;
	std::cout << BOLDBLUE << "   PROGRAM ENDED" << std::endl;
	std::cout << BOLDWHITE << "===================" << std::endl;
	return (0);
}
