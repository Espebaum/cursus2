#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string scavname) : ClapTrap(scavname)
{
	this->name = scavname;
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 20;
	std::cout << BOLDWHITE << "I am " << BOLDYELLOW << this->name << \
	BOLDWHITE << ", Inheritor of CLAP-TRAP!!!" << std::endl << std::endl;
}

ScavTrap::ScavTrap() : ClapTrap()
{
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 20;
	std::cout << BOLDWHITE << "I am " << BOLDYELLOW << this->name << \
	BOLDWHITE << ", Inheritor of CLAP-TRAP!!!" << std::endl << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &ref)
{
	std::cout << BOLDYELLOW << ref.getName() << BOLDWHITE << " : " << "NOW, I'm coping myself!!!" << std::endl;
	*this = ref;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap &ref)
{
	std::cout << BOLDGREEN << "Assigning Operation Started" << std::endl;
	if (this != &ref)
	{
		this->name = ref.getName();
		this->HitPoints = ref.HitPoints;
		this->EnergyPoints = ref.EnergyPoints;
		this->AttackDamage = ref.AttackDamage;
	}
	return (*this);
}

void	ScavTrap::attack(const std::string& target)
{
	if (getEnergyPoints() <= 0)
	{
		std::cout << BOLDYELLOW << this->name << BOLDWHITE << " : " << "I need Energy to move, FOOL!!" << std::endl;
		return ;
	}
	std::cout << BOLDYELLOW << this->name << BOLDWHITE << " attacks " << BOLDRED << target \
	<< BOLDWHITE << ", causing " << this->AttackDamage << " points of damage!" << std::endl;
	if (getAttackDamage() == 0)
	{
		std::cout << BOLDYELLOW << this->name << BOLDWHITE << " : " << "Oh, I missed it..." << std::endl;
	}
	else
		std::cout << BOLDGREEN << "A Singular Strike!" << std::endl;
	setEnergyPoints();
	std::cout << std::endl;
}

void	ScavTrap::guardGate()
{
	if (this->getEnergyPoints() > 0)
	{
		std::cout << BOLDYELLOW << this->name << BOLDMAGENTA << \
		" has entered gate guard mode." << std::endl << std::endl;
	}
	else
	{
		std::cout << BOLDYELLOW << this->name << BOLDMAGENTA << \
		" is out of energy, stopping gate guard mode." << std::endl << std::endl;
	}
}

ScavTrap::~ScavTrap()
{
	std::cout << BOLDYELLOW << this->name << BOLDWHITE << " : I, " << \
	BOLDYELLOW << "the Inheritor of CLAP-TRAP" << BOLDWHITE << ", am leaving now..." << std::endl;
}
