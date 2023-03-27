#include "ClapTrap.hpp"

int	main()
{
	const std::string	target = "DUMMY";
	ClapTrap	Clap("CL4P-TP");

	std::cout << BOLDWHITE << "My name is ";
	Clap.showName(); 
	std::cout << std::endl;

	Clap.attack(target);
	Clap.attack(target);
	Clap.attack(target);

	// std::cout << "AttackDamage : " << Clap.getAttackDamage() << std::endl;
	std::cout << "HP : " << Clap.getHitPoints() << std::endl;
	Clap.takeDamage(4);
	std::cout << BOLDWHITE;
	std::cout << "HP : " << Clap.getHitPoints() << std::endl;
	Clap.beRepaired(4);
	std::cout << "HP : " << Clap.getHitPoints() << std::endl;
	return (0);
}
