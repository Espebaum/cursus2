#include "ClapTrap.hpp"

int	main()
{
	const std::string	target = "DUMMY";
	// FragTrap	frag1;
	ClapTrap*	clap;
	FragTrap	frag2("FRAG-TRAP");
	clap = &frag2;

	// clap->highFivesGuy(); //this command occurs Error!
	clap->attack(target); //but this command does not occur Error
	frag2.attack(target);
	frag2.takeDamage(rand() % 10);
	frag2.showAllStatus();
	frag2.highFivesGuy();

	std::cout << BOLDWHITE << "===================" << std::endl;
	std::cout << BOLDBLUE << "   PROGRAM ENDED" << std::endl;
	std::cout << BOLDWHITE << "===================" << std::endl;
	return (0);
}
