#include "HumanB.hpp"

HumanB::HumanB()
{
	std::cout << "but no one appeared..." << std::endl ;
}

HumanB::HumanB(std::string name)
{
	this->name = name;
}

HumanB::~HumanB() {}

void	HumanB::setWeapon(Weapon &club)
{
	this->param = &club;
}

std::string HumanB::isArmed(std::string s) const
{
	if (s == "")
		return "Fists";
	return (s);
}

void HumanB::attack()
{
	std::cout << BOLDBLUE << this->name << BOLDWHITE << " attacks with their " << BOLDRED << isArmed(this->param->getType()) << std::endl;
}
