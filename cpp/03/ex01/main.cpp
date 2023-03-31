#include "ClapTrap.hpp"

int	main()
{
	const std::string	target = "DUMMY";
	// ScavTrap	scav1;
	ClapTrap*	clap;
	ScavTrap	scav2("SCAV-TRAP");
	clap = &scav2;

	// clap->guardGate(); //this command occurs Error!
	clap->attack(target); //but this command does not occur Error
	scav2.guardGate();
	scav2.attack(target);
	scav2.takeDamage(rand() % 10);
	scav2.showAllStatus();

	std::cout << BOLDWHITE << "===================" << std::endl;
	std::cout << BOLDBLUE << "   PROGRAM ENDED" << std::endl;
	std::cout << BOLDWHITE << "===================" << std::endl;
	return (0);
}
